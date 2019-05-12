make
#		pattern_only
./checker -p						# no arguments
./checker -p 547					# no arguments
./checker -p 547 8
./checker -p "547"					# no arguments
./checker -p "547" "8"
./checker "-p 547" "8"
./checker "-p 547" 8
./checker "-p" 8 coucou				# error
./checker "-p" 8 coucou 3			# error
./checker "-p salut" 8 coucou 3		# error
./checker "-p salut 5" 8 coucou 3	# error
#		help_only
./checker -h
./checker -h 547
./checker -h 547 8
./checker -h "547"
./checker -h "547" "8"
./checker "-h 547" "8"
./checker "-h 547" 8
./checker "-h" 8 coucou				# error
./checker "-h" 8 coucou 3			# error
./checker "-h salut" 8 coucou 3		# error
./checker "-h salut 5" 8 coucou 3	# error
#		help_only_pattern_mute
./checker -hp
./checker -hp 547
./checker -hp 547 8
./checker -hp "547"
./checker -hp "547" "8"
./checker "-hp 547" "8"
./checker "-hp 547" 8
./checker "-hp" 8 coucou			# error
./checker "-hp" 8 coucou 3			# error
./checker "-hp salut" 8 coucou 3	# error
./checker "-hp salut 5" 8 coucou 3	# error
#		help_only_pattern_mute_reverse
./checker -ph
./checker -ph 547
./checker -ph 547 8
./checker -ph "547"
./checker -ph "547" "8"
./checker "-ph 547" "8"
./checker "-ph 547" 8
./checker "-ph" 8 coucou			# error
./checker "-ph" 8 coucou 3			# error
./checker "-ph salut" 8 coucou 3	# error
./checker "-ph salut 5" 8 coucou 3	# error
#		file
./checker -f
./checker -f 547
./checker -f 547 8
./checker -f "547"
./checker -f "547" "8"
./checker "-f 547" "8"
./checker "-f 547" 8
./checker "-f" 8 coucou
./checker "-f" 8 coucou 3
./checker "-f salut" 8 coucou 3
./checker "-f salut 5" 8 coucou 3
#		edit
./checker -e
./checker -e 547
./checker -e 547 8
./checker -e "547"
./checker -e "547" "8"
./checker "-e 547" "8"
./checker "-e 547" 8
./checker "-e" 8 coucou
./checker "-e" 8 coucou 3
./checker "-e salut" 8 coucou 3
./checker "-e salut 5" 8 coucou 3