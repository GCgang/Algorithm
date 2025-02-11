function solution(numbers) {
  let numSet = new Set();

  function getPermutations(arr) {
    function permute(current, remaining) {
      if (current.length > 0) numSet.add(parseInt(current.join('')));
      if (remaining.length === 0) return;

      for (let i = 0; i < remaining.length; i++) {
        let newArr = remaining.slice(0, i).concat(remaining.slice(i + 1));
        permute([...current, remaining[i]], newArr);
      }
    }

    permute([], arr);
  }

  function isPrime(n) {
    if (n < 2) return false;
    for (let i = 2; i <= Math.sqrt(n); i++) {
      if (n % i === 0) return false;
    }
    return true;
  }

  getPermutations(numbers.split(''));

  return [...numSet].filter(isPrime).length;
}
