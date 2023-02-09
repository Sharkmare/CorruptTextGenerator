import random

def corrupt_text(text):
    corrupters = ["0", "@", "&", "%", "$", "§"]
    text_length = len(text)
    corruption_count = int(text_length / 10)
    for i in range(corruption_count):
        char_index = random.randint(0, text_length - 1)
        if text[char_index] != " ":
            text = text[:char_index] + corrupters[random.randint(0, len(corrupters) - 1)] + text[char_index + 1:]
        else:
            i -= 1

    return text

def main():
    original_text = "some random string"
    corrupted_text = corrupt_text(original_text)
    print("Original text:", original_text)
    print("Corrupted text:", corrupted_text)

main()
