// https://school.programmers.co.kr/learn/courses/30/lessons/132267

function solution(a, b, n) {
  let totalCoke = 0;
  let emptyBottle = n;

  while (emptyBottle >= a) {
    const newCoke = Math.floor(emptyBottle / a) * b;
    const remainingBottles = emptyBottle % a;
    totalCoke += newCoke;
    emptyBottle = newCoke + remainingBottles;
  }

  return totalCoke;
}

solution2 = (a, b, n) => Math.floor(Math.max(n - b, 0) / (a - b)) * b;
