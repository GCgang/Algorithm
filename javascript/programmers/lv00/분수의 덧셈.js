// https://school.programmers.co.kr/learn/courses/30/lessons/120808

function solution(numer1, denom1, numer2, denom2) {
  // 최대 공약수 (GCD)
  const gcd = (a, b) => {
    while (b !== 0) {
      [a, b] = [b, a % b];
    }
    return a;
  };
  // 최소 공배수 (LCM)
  const lcm = (a, b) => (a * b) / gcd(a, b);

  // 공통 분모 계산
  const commonDenom = lcm(denom1, denom2);

  // 분자 조정
  const newNumer1 = numer1 * (commonDenom / denom1);
  const newNumer2 = numer2 * (commonDenom / denom2);

  // 분자끼리 더하기
  const resultNumer = newNumer1 + newNumer2;
  const resultDenom = commonDenom;

  // 기약분수로 만들기
  const resultGCD = gcd(resultNumer, resultDenom); // 최대공약수
  const finalNumer = resultNumer / resultGCD;
  const finalDenom = resultDenom / resultGCD;

  return [finalNumer, finalDenom];
}
