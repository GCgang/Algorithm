// https://school.programmers.co.kr/learn/courses/30/lessons/12926?language=javascript
function solution(s, n) {
  const lower = 'abcdefghijklmnopqrstuvwxyz';
  const upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  let result = '';

  for (let c of s) {
    if (c === ' ') {
      result += ' ';
    } else if (lower.includes(c)) {
      result += lower[(lower.indexOf(c) + n) % 26];
    } else if (upper.includes(c)) {
      result += upper[(upper.indexOf(c) + n) % 26];
    }
  }
  return result;
}

// function solution(s, n) {
//     let result = "";

//     for (let char of s) {
//         if (char === " ") {
//             result += " ";
//         } else {
//             const base = char >= "A" && char <= "Z" ? "A".charCodeAt(0) : "a".charCodeAt(0);
//             const shifted = (char.charCodeAt(0) - base + n) % 26;
//             result += String.fromCharCode(base + shifted);
//         }
//     }

//     return result;
// }
