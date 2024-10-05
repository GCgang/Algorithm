// https://school.programmers.co.kr/learn/courses/30/lessons/12939

function solution(s) {
  const arr = s.split(' ');
  const min = Math.min(...arr);
  const max = Math.max(...arr);
  return `${min} ${max}`;
}
