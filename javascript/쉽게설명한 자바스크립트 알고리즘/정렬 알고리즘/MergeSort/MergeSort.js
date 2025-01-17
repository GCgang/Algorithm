function mergeSort(array) {
  if (array.length <= 1) return array;

  const mid = Math.floor(array.length / 2);
  const left = mergeSort(array.slice(0, mid));
  const right = mergeSort(array.slice(mid));

  return merge(left, right);
}

function merge(left, right) {
  const result = [];
  let lIndex = 0,
    rIndex = 0;

  while (lIndex < left.length && rIndex < right.length) {
    if (left[lIndex] < right[rIndex]) {
      result.push(left[lIndex++]);
    } else {
      result.push(right[rIndex++]);
    }
  }

  while (lIndex < left.length) result.push(left[lIndex++]);
  while (rIndex < right.length) result.push(right[rIndex++]);

  return result;
}

console.log(mergeSort([3, 4, 1, 2, 6, 5, 2]));
