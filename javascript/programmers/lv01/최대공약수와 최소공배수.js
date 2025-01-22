// https://school.programmers.co.kr/learn/courses/30/lessons/12940
// 최대공약수
function gcd(a, b) {
  while (b !== 0) {
    let r = b;
    b = a % b;
    a = r;
  }
  return a;
}

// 최소공배수
function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

function solution(n, m) {
  return [gcd(n, m), lcm(n, m)];
}
