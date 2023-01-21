vocab = "abcdefghijklmnopqrstuvwxyz"

### Define numerical representation of text ###

# Create a mapping from character to unique index.
# For example, to get the index of the character "d", 
#   we can evaluate `char2idx["d"]`.  
char2idx = {u:i for i, u in enumerate(vocab)}

for char in char2idx:
    print(char)

print("\n")

# Create a mapping from indices to characters. This is
#   the inverse of char2idx and allows us to convert back
#   from unique index to the character in our vocabulary.
idx2char = list(vocab)

print('{')
for char,_ in zip(char2idx, range(20)):
    print('  {:4s}: {:3d},'.format(repr(char), char2idx[char]))
print('  ...\n}')

string = 'jahrgliaugrhiluaerhgliuaehrgluieahrgluierahgliuagehr'

vectorized_output = list([char2idx[iter]] for iter in string)

print(vectorized_output)