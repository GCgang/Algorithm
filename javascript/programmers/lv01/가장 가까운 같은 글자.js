// https://school.programmers.co.kr/learn/courses/30/lessons/142086

function solution(s) {
  let lastIndex = {};
  let result = [];

  for (let i = 0; i < s.length; i++) {
    const char = s[i];

    if (lastIndex[char] !== undefined) {
      result.push(i - lastIndex[char]);
    } else {
      result.push(-1);
    }

    lastIndex[char] = i;
  }
  return result;
}
