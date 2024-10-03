// https://school.programmers.co.kr/learn/courses/30/lessons/131705

function getCombinations(arr, selectNumber) {
  const results = [];
  if (selectNumber === 1) return arr.map((val) => [val]);

  arr.forEach((fixed, i, origin) => {
    const rest = origin.slice(i + 1);
    const combinations = getCombinations(rest, selectNumber - 1);
    const attached = combinations.map((comb) => [fixed, ...comb]);
    results.push(...attached);
  });
  return results;
}

function solution(number) {
  let count = 0;
  const combinations = getCombinations(number, 3);
  combinations.forEach((comb) => {
    const sum = comb.reduce((acc, cur) => acc + cur, 0);
    if (sum === 0) count++;
  });

  return count;
}
