// https://school.programmers.co.kr/learn/courses/30/lessons/120812
function solution(array) {
  const frequencyMap = new Map();

  array.forEach((num) => {
    frequencyMap.set(num, (frequencyMap.get(num) || 0) + 1);
  });

  const sortedMap = [...frequencyMap].sort((a, b) => b[1] - a[1]);

  if (sortedMap.length === 1 || sortedMap[0][1] !== sortedMap[1][1]) {
    return sortedMap[0][0];
  } else {
    return -1;
  }
}
