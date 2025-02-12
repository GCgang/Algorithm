// https://school.programmers.co.kr/learn/courses/30/lessons/42578
function solution(clothes) {
  const clothesMap = new Map();

  for (let [name, type] of clothes) {
    clothesMap.set(type, (clothesMap.get(type) || 0) + 1);
  }

  let result = 1;
  for (let cnt of clothesMap.values()) {
    result *= cnt + 1;
  }

  return result - 1;
}
