from collections import defaultdict


def num_words(num, text):
    def num_words_count():
        return num_words(num, text).count()

    def make_word_counts():
        words = text.split()
        word_counts = defaultdict(int)
        for word in words:
            word_counts[word] += 1
        return word_counts

    def count_same_num_words(word_counts):
        count = 0
        for k, v in word_counts.items():
            if v == num:
                count += 1
        return count

    word_counts = make_word_counts()
    return count_same_num_words(word_counts)
