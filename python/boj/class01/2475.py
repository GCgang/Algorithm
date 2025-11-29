numbers = list(map(int, input().split()))

check_digit =  sum(num ** 2 for num in numbers) % 10

print(check_digit)



