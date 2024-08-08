## 문제 (08.js)

괄호 짝 맞추기

- 소괄호는 짝을 맞춘 열린 괄호 '(' 와 닫힌 괄호 ')' 로 구성한다
- 열린 괄호와 닫힌 괄호가 마구 뒤섞인 문자열을 준다
- 이때 소괄호가 정상으로 열고 닫혔는지 판별하는 solution() 함수를 구현 하라
- 만약 소괄호가 정상적으로 열고 닫혔다면 true, 그렇지 않다면 false를 반환 하면 된다

제약 조건

- 열린 괄호는 자신과 가장 가까운 닫힌 괄호를 만나면 상쇄된다
- 상쇄 조건은 열린 괄호가 먼저 와야 하고, 열린 괄호와 닫힌 괄호 사이에 아무것도 없어야 한다
- 더 상쇄할 괄호가 없을 때까지 상쇄를 반복한다

권장 시간 복잡도: `O(N)`

## 풀이

1. 문자열을 앞에서부터 하나씩 보며 열린 괄호가 나오면 push
2. 닫힌 괄호가 나온 경우 stack이 비어있으면 false, 비어있지 않다면 열린 괄호가 있다는 것이므로 pop
3. stack이 비어있어야 짝이 맞은 것으로 판단하여 true, 비어있지 않다면 false 반환

## Reference

- [MDN for...of](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...of)
- [MDN Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
- [MDN Array.prototype.pop()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/pop)
