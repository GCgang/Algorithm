## 문제 (18.js)

- [완주하지 못한 선수](https://school.programmers.co.kr/learn/courses/30/lessons/42576?language=javascript)

권장 시간 복잡도: `O(N)`

## 풀이

1. 참가자들의 이름을 해쉬테이블에 저장
2. 완주한 선수의 이름을 키로하는 값 1씩 감소
3. 해시 테이블에 남아 있는 선수가 완주하지 못한 선수 이므로 확인 후 return

## Reference

- [for...of](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Statements/for...of)
- [for...in](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Statements/for...in)
