## 문제 (15.js)

15. 요세푸스 문제
    N명의 사람이 원 형태로 서 있다. 각 사람은 1부터 N까지 번호표를 갖고 있다. 그리고 임의의 숫자 K가 주어졌을 때 다음과 같이 사람을 없앤다.

- 1번 번호표를 가진 사람을 기준으로 K번째 사람을 없앱니다.
- 없앤 사람 다음 사람을 기준으로 하고 다시 K번째 사람을 없앱니다.

  N과 K가 주어질 때 마지막에 살아있는 사람의 번호를 반환하는 solution()함수를 구현해주세요.

제약 조건

- N과 K는 1이상 1000이하의 자연수입니다.

권장 시간 복잡도: `O(N * K)`

## 풀이

- N만큼 큐에 넣기
- 마지막 한사람이 남을 때까지 반복
- k - 1 명은 맨 앞에서 맨 뒤로 보내기(k번째 사람을 제거하기 위함)
- k번째 사람 제거
- 마지막 남은 사람 번호 반환

## Reference

- [MDN class](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/class)
- [MDN Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
- [MDN Array.prototype.pop()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/pop)
