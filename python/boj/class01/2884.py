h, m = map(int, input().split())

m -= 45

if m < 0:
    h -= 1
    m += 60

if h < 0:
    h = 23

print(h, m)


# 2
h, m = map(int, input().split())
total_minutes = h * 60 + m
total_minutes -= 45

if total_minutes < 0:
    total_minutes += 24 * 60

h = total_minutes // 60
m = total_minutes % 60

print(h, m)
