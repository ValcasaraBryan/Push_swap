make
#		pattern_only
./checker -p			# no arguments
./checker -p 547		# no arguments
./checker -p 547 8
./checker -p "547"		# no arguments
./checker -p "547" "8"
./checker "-p 547" "8"
./checker "-p 547" 8
./checker "-p" 8 coucou	# no arguments
./checker "-p" 8 coucou 3
./checker "-p salut" 8 coucou 3
./checker "-p salut 5" 8 coucou 3
#		help_only
./checker -h
./checker -h 547
./checker -h 547 8
./checker -h "547"
./checker -h "547" "8"
./checker "-h 547" "8"
./checker "-h 547" 8
./checker "-h" 8 coucou
./checker "-h" 8 coucou 3
./checker "-h salut" 8 coucou 3
./checker "-h salut 5" 8 coucou 3
#		help_only_pattern_mute
./checker -hp
./checker -hp 547
./checker -hp 547 8
./checker -hp "547"
./checker -hp "547" "8"
./checker "-hp 547" "8"
./checker "-hp 547" 8
./checker "-hp" 8 coucou
./checker "-hp" 8 coucou 3
./checker "-hp salut" 8 coucou 3
./checker "-hp salut 5" 8 coucou 3
#		help_only_pattern_mute_reverse
./checker -ph
./checker -ph 547
./checker -ph 547 8
./checker -ph "547"
./checker -ph "547" "8"
./checker "-ph 547" "8"
./checker "-ph 547" 8
./checker "-ph" 8 coucou
./checker "-ph" 8 coucou 3
./checker "-ph salut" 8 coucou 3
./checker "-ph salut 5" 8 coucou 3
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