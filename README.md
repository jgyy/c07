# C Piscine C 07

**Staff 42 pedago@42.fr**

*Summary: This document is the subject for the module C 07 of the C Piscine @ 42.*

*Version: 4.3*

## Contents

1. [Instructions](#instructions)
2. [Foreword](#foreword)
3. [Exercise 00 : ft_strdup](#exercise-00--ft_strdup)
4. [Exercise 01 : ft_range](#exercise-01--ft_range)
5. [Exercise 02 : ft_ultimate_range](#exercise-02--ft_ultimate_range)
6. [Exercise 03 : ft_strjoin](#exercise-03--ft_strjoin)
7. [Exercise 04 : ft_convert_base](#exercise-04--ft_convert_base)
8. [Exercise 05 : ft_split](#exercise-05--ft_split)
9. [Submission and peer-evaluation](#submission-and-peer-evaluation)

## Instructions

- Only this page will serve as reference: do not trust rumors.
- Watch out! This document could potentially change before submission.
- Make sure you have the appropriate permissions on your files and directories.
- You have to follow the submission procedures for all your exercises.
- Your exercises will be checked and graded by your fellow classmates.
- On top of that, your exercises will be checked and graded by a program called Moulinette.
- Moulinette is very meticulous and strict in its evaluation of your work. It is entirely automated and there is no way to negotiate with it. So if you want to avoid bad surprises, be as thorough as possible.
- Moulinette is not very open-minded. It won't try and understand your code if it doesn't respect the Norm. Moulinette relies on a program called norminette to check if your files respect the norm. TL;DR: it would be idiotic to submit a piece of work that doesn't pass norminette's check.
- These exercises are carefully laid out by order of difficulty - from easiest to hardest. We will not take into account a successfully completed harder exercise if an easier one is not perfectly functional.
- Using a forbidden function is considered cheating. Cheaters get -42, and this grade is non-negotiable.
- You'll only have to submit a main() function if we ask for a program.
- Moulinette compiles with these flags: -Wall -Wextra -Werror, and uses cc.
- If your program doesn't compile, you'll get 0.
- You cannot leave any additional file in your directory than those specified in the subject.
- Got a question? Ask your peer on the right. Otherwise, try your peer on the left.
- Your reference guide is called Google / man / the Internet / ....
- Check out the "C Piscine" part of the forum on the intranet, or the slack Piscine.
- Examine the examples thoroughly. They could very well call for details that are not explicitly mentioned in the subject...
- By Odin, by Thor ! Use your brain !!!

Norminette must be launched with the -R CheckForbiddenSourceHeader flag. Moulinette will use it too.

## Foreword

*[Rick and Morty dialogue omitted for brevity]*

The following exercises will be easier to complete if you are a fan of "Rick and Morty"

## Exercise 00 : ft_strdup

**Turn-in directory:** ex00/
**Files to turn in:** ft_strdup.c
**Allowed functions:** malloc

- Reproduce the behavior of the function strdup (man strdup).
- Here's how it should be prototyped:

```c
char *ft_strdup(char *src);
```

## Exercise 01 : ft_range

**Turn-in directory:** ex01/
**Files to turn in:** ft_range.c
**Allowed functions:** malloc

- Create a function ft_range which returns an array of ints. This int array should contain all values between min and max.
- Min included - max excluded.
- Here's how it should be prototyped:

```c
int *ft_range(int min, int max);
```

- If min's value is greater or equal to max's value, a null pointer should be returned.

## Exercise 02 : ft_ultimate_range

**Turn-in directory:** ex02/
**Files to turn in:** ft_ultimate_range.c
**Allowed functions:** malloc

- Create a function ft_ultimate_range which allocates and assigns an array of ints.
- This int array should contain all values between min and max.
- Min included - max excluded.
- Here's how it should be prototyped:

```c
int ft_ultimate_range(int **range, int min, int max);
```

- The size of range should be returned (or -1 on error).
- If the value of min is greater or equal to max's value, range will point on NULL and it should return 0.

## Exercise 03 : ft_strjoin

**Turn-in directory:** ex03/
**Files to turn in:** ft_strjoin.c
**Allowed functions:** malloc

- Write a function that will concatenate all the strings pointed by strs separated by sep.
- size is the number of strings in strs
- if size is 0, you must return an empty string that you can free().
- Here's how it should be prototyped:

```c
char *ft_strjoin(int size, char **strs, char *sep);
```

## Exercise 04 : ft_convert_base

**Turn-in directory:** ex04/
**Files to turn in:** ft_convert_base.c, ft_convert_base2.c
**Allowed functions:** malloc, free

- Create a function that returns the result of the conversion of the string nbr from a base base_from to a base base_to.
- nbr, base_from, base_to may be not writable.
- nbr will follow the same rules as ft_atoi_base (from another module). Beware of '+', '-' and whitespaces.
- The number represented by nbr must fit inside an int.
- If a base is wrong, NULL should be returned.
- The returned number must be prefix only by a single and unique '-' if necessary, no whitespaces, no '+'.
- Here's how it should be prototyped:

```c
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
```

## Exercise 05 : ft_split

**Turn-in directory:** ex05/
**Files to turn in:** ft_split.c
**Allowed functions:** malloc

- Create a function that splits a string of character depending on another string of characters.
- You'll have to use each character from the string charset as a separator.
- The function returns an array where each element of the array contains the address of a string wrapped between two separators. The last element of that array should equal to 0 to indicate the end of the array.
- There cannot be any empty strings in your array. Get your own conclusions accordingly.
- The string given as argument won't be modifiable.
- Here's how it should be prototyped:

```c
char **ft_split(char *str, char *charset);
```

## Submission and peer-evaluation

Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don't hesitate to double check the names of your files to ensure they are correct.

You need to return only the files requested by the subject of this project.
