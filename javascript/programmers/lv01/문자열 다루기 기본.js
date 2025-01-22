// https://school.programmers.co.kr/learn/courses/30/lessons/12918
function solution(s) {
  if (s.length !== 4 && s.length !== 6) return false;
  for (let c of s) {
    if (isNaN(c) || c === ' ') return false;
  }
  return true;
}

// function solution(s) {
//  const regex = /^[0-9]{4}$|^[0-9]{6}$/;

//     return regex.test(s)
// }
