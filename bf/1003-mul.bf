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

[-<<<+>>>]<<<	c0 = c3 ; c3 = 0 ; end c0

>[-]>[-]>[-]>[-]>[-]>[-]>[-]<<<<<<<

Up to here everything is fine  Multiplication Result in c0

[->+>+<<]>>[-<<+>>]   c1 = c0; end c2
++++++++++	      c2 = 10;
<[		      while(c1){
-			c1 menos= 1
>-		      	c2 menos= 1; end c2
[->+>+<<]>>[-<<+>>]<  	c3 = c2; end c3
[>+<[-]]+>[<->-]<    	c3 = NOT c3; end c3
[		      	if(c3){
<++++++++++		   c2 = 10
>>>+		      	   c5 mas= 1
<<-		      	   c3 = 0
]		      	}
<<			place c1
]		      }
>>>>		      place c5
>[-]>[-]<<		c6 = c7 = 0
[->+>+<<]>>[-<<+>>]<  	c6 = c5; end c6

[		      if(c6){ c6 = 0
>++++ ++++		print c6
[-<+++ +++>]<.	      	#
>++++ ++++		#
[-<--- --->]<		#
[-]
]      		      }

<		      place c5

[-<<<<++++++++++>>>>]	c1 = 10 * c5
<<<<		      place c1
[-<->]<		      c0 = c0 menos c1; c1 = 0; end c0

>++++ ++++		print c0
[-<+++ +++>]<.	      	#
>++++ ++++		#
[-<--- --->]<		#

>++++++++++.		print \n