"""
    reverse words
    author oinegexruam@
"""

def reverse_word(word):
    word_reverse = ''
    for i in range(1, len(word) + 1):
        index_reverse = len(word) - i
        word_reverse += word[index_reverse]
    return word_reverse

reverse_word(str(input('type a word: ')))
