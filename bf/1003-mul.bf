[-]>[-]>[-]>[-]>[-]>[-]<<<<< c1=c2=c3=c4=c5=0
>>>>>>>>>,
<<<<<<<<<
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

>>>		place c3 Multiplication Result



Up to here everything is fine

[-<<<+>>>]	c0 = c3 ; c3 = 0 ; end c3
>>++++ ++++ ++	place c5 = 10
<<<<<		place c0
>[-]>[-]>[-]>[-]<<<<  c1=c2=c3=c4 = 0
		c0=mul c5 = 10 everything else is cero


########### c2 = (c0 mayor que 10) ##################
[->+>+<<]	c1 = c2 = c0; c0 = 0; end c0
>>		place c2
[<<+>>-]	c0 = c2; c2 = 0; end c2

>[-]>[-]<<	c3 = c4 = 0; end c2

<		place c1
[		
>>+		place c3 = 1
>>[-<<[-]>+>]	if(c5){c4 = c5; c5 = 0; c3 = 0}; end c5
<<[- <+ >]	if(c3){c2 = algo}; end c3
>[->+<]		c5 = c4; c4 = 0; end c4;
>-<<<<-		c5 menos=1 c1 menos=1; end c1
]
########## END c2 = (c0 mayor que 10)#################



#############################################
		if (c2){   convert c0     }
>		place c2
>[-]>[-]<<	c3 = c4 = 0; end c2
[>+>+<<-]>[-<+>]+  c4 = c2; c3 = 1; end c3
>		place c4
[		if(c4){
<<<<		place c0
[->>>>>+<<<<<]	c5 = c0; c0 = 0; end c0
>>>>>		place c5
<		place c4
<->[-]		c3 = 0 c4 = 0; end c4
]		}

#############################################
		else {print c0}

<[[-]		place c3; else{ c3 = 0
<<<		place c0
>[-]<		c1 = 0; end c0
>++++ ++++ 	place c1 = 8
[-<++++++>]<	c0 mas= 48; c1 = 0; end c0
.		print c0
>>>		place c3
]		}


