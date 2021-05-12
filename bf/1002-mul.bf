,		place c0 and read
>++++ ++++	c1 = 8
[-<--- --->]<	c0 menos= 48; c1 = 0; end c0
>,     		place c1 and read
>++++ ++++	c2 = 8
[-<--- --->]<	c1 menos= 48; c2 = 0; end c1

<      		place c0
[-		c0 menos= 1
		   #make a copy of c1 in c2
>		   place c1
[->+>+<<] 	   make a copy in c2 and c3; c1 = 0; end c1
>		   c2
[<+>-]		   c1 = c2; c2 = 0; end c2
>		   c3
[<+>-]		   c2 = c3; c3 = 0; end c3
<		   place c2
[->+<]		   c3 mas= c2; c2 = 0; end c2
<<		   place c0
]

>>>		place c3

>++++ ++++ 	place c4 = 8
[-<++++++>]	# c3 mas= 48; c4 = 0; end c4

<.     	   	# print c3
