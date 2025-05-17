#!/usr/bin/python3
import requests
import re


def count_words(subreddit, word_list, after=None, counts=None):
    if counts is None:
        # Normalize word_list to lowercase
        word_list_lower = [w.lower() for w in word_list]
        counts = {}
        # Initialize counts dict with keys as unique words in word_list_lower
        for w in set(word_list_lower):
            counts[w] = 0
        # Save original list for duplicate handling at the end
        count_words.word_list_lower = word_list_lower

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'Mozilla/5.0'}
    params = {'limit': 100}
    if after:
        params['after'] = after

    try:
        response = requests.get(
            url, headers=headers, params=params, allow_redirects=False
        )
        if response.status_code != 200:
            return
        data = response.json()
    except Exception:
        return

    if 'data' not in data or 'children' not in data['data']:
        return

    posts = data['data']['children']

    for post in posts:
        title = post['data'].get('title', '').lower()

        # Count occurrences for using regex whole word matching
        for keyword in counts.keys():
            # pattern to match whole word exactly (word boundary \b)
            pattern = r'\b' + re.escape(keyword) + r'\b'
            matches = re.findall(pattern, title)
            counts[keyword] += len(matches)

    after = data['data'].get('after')
    if after:
        return count_words(subreddit, word_list, after, counts)
    else:
        # Aggregate counts for duplicates in word_list
        final_counts = {}
        for word in set(count_words.word_list_lower):
            # sum counts for all duplicates of this word in word_list_lower
            final_counts[word] = (
                counts[word] * count_words.word_list_lower.count(word)
            )

        # Filter out zero counts
        filtered = {k: v for k, v in final_counts.items() if v > 0}
        if not filtered:
            return

        # Sort by count desc, then word asc
        sorted_counts = sorted(filtered.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            print(f"{word}: {count}")
