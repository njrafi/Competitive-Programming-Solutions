def mutate_string(string, position, character):
    a = list(string)
    a[position] = character
    a = ''.join(a)
    return a