// https://school.programmers.co.kr/learn/courses/30/lessons/12944

function solution(arr) {
  return arr.reduce((acc, cur) => acc + cur) / arr.length;
}
