scale = list(map(int, (input().split())))

diffs = [scale[i+1] - scale[i] for i in range(7)]

if diffs == [1] * 7:
    print('ascending')
elif diffs == [-1] * 7:
    print('descending')
else:
    print('mixed')
