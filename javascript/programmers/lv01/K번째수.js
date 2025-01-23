// https://school.programmers.co.kr/learn/courses/30/lessons/42748?language=javascript

function solution(array, commands) {
  return commands.map(
    ([i, j, k]) => array.slice(i - 1, j).sort((a, b) => a - b)[k - 1]
  );
}

function solution2(array, commands) {
  const result = [];

  for (let [i, j, k] of commands) {
    const sliced = array.slice(i - 1, j);
    const sorted = sliced.sort((a, b) => a - b);
    result.push(sorted[k - 1]);
  }

  return result;
}
