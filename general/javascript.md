Online Playgrouds
----
There are many browser-based JavaScript playgrounds, for easy testing and sharing frontend programms.
The following two are my favorites:
- StackBlitz (https://stackblitz.com/)
- CodeSanbox (https://codesandbox.io/)

Rounding Numbers
----
Rounding a number is not an easy task. To round a number to nearest hundredth, I wrote:
```
let num = 1/3;
let result = Math.round(100 * num) / 100;
```
But this causes problem for `1.005` which should be rounded to `1.01`, but the above code gets `1.00`.

It's better to add the smallest interval between two float numbers, say `Number.EPSILON` before rounding:
```
let num = 1.005;
let result = Math.round(100 * (num + Number.EPSILON)) / 100;
```

The out-of-box one is `lodash.round()`.