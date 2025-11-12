## Binary Search (Index Flow Only)

Array indexes:
`0  1  2  3  4  5`
Values: `5, 10, 15, 20, 25, 30`

---

### Example 1: Searching for `25`

```
low = 0, high = 5  →  mid = 2   (check index 2)
low = 3, high = 5  →  mid = 4   found at index 4
```

---

### Example 2: Searching for `13`

```
low = 0, high = 5  →  mid = 2
low = 0, high = 1  →  mid = 0
low = 1, high = 1  →  mid = 1
low = 2, high = 1  →  stop (not found)
```

---
Each time, binary search cuts the range in half - it updates:

* `low = mid + 1` if the value is too small
* `high = mid - 1` if the value is too large

This keeps shrinking the search window until the element is found or the range is empty.
