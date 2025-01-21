// https://school.programmers.co.kr/learn/courses/30/lessons/12903
function solution(s) {
  const mid = Math.floor(s.length / 2);

  if (s.length % 2 === 0) {
    return s.slice(mid - 1, mid + 1);
  } else {
    return s.slice(mid, mid + 1);
  }
}

// function solution(s) {
//     const mid = Math.floor(s.length / 2);

//     return s.length % 2 === 0 ? s[mid - 1] + s[mid] : s[mid];
// }
