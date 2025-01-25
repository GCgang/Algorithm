// https://school.programmers.co.kr/learn/courses/30/lessons/133499

function solution(babbling) {
  const regex = /^(aya|ye|woo|ma)+$/; // 가능한 발음 조합만 허용
  const repeatRegex = /(aya|ye|woo|ma)\1/; // 같은 발음이 연속되면 불가

  return babbling.filter((word) => regex.test(word) && !repeatRegex.test(word))
    .length;
}
