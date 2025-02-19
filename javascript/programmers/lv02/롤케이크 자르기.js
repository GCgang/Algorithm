// https://school.programmers.co.kr/learn/courses/30/lessons/132265
function solution(topping) {
  let leftSet = new Set();
  let rightMap = new Map();
  let count = 0;

  for (let t of topping) {
    rightMap.set(t, (rightMap.get(t) || 0) + 1);
  }

  for (let t of topping) {
    leftSet.add(t);
    rightMap.set(t, rightMap.get(t) - 1);

    if (rightMap.get(t) === 0) {
      rightMap.delete(t);
    }

    if (leftSet.size === rightMap.size) count++;
  }

  return count;
}
