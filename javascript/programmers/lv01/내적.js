// https://school.programmers.co.kr/learn/courses/30/lessons/70128
// a[n-1]*b[n-1]
// // 재귀
// function solution(a, b, i = 0) {
//     if (i >= a.length) return 0;

//     return a[i] * b[i] + solution(a, b, i + 1);
// }

// reduce
function solution(a, b) {
  return a.reduce((acc, cur, i) => acc + cur * b[i], 0);
}
