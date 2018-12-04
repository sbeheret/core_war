#top file comment
#more
#and more
.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1 #inline comment
		and r1, %0, r1

#between lines comment

live:	live %1
		zjmp %:live

#end file comment
