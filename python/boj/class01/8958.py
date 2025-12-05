def grade(quiz):
    score = 0
    streak = 0

    for char in quiz:
        if char == 'O':
            streak += 1
            score += streak
        else:
            streak = 0

    return score

tc = int(input())

for _ in range(tc):
    print(grade(input()))

