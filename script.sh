make
#		pattern_only
#valgrind --leak-check=full
 ./checker -p							# patern
#valgrind --leak-check=full
 ./checker -p 547						# patern
#valgrind --leak-check=full
 ./checker -p 547 8					# patern
#valgrind --leak-check=full
 ./checker -p "547"					# patern
#valgrind --leak-check=full
 ./checker -p "547" "8"				# patern
#valgrind --leak-check=full
 ./checker "-p 547" "8"				# patern
#valgrind --leak-check=full
 ./checker "-p 547" 8					# patern
#valgrind --leak-check=full
 ./checker "-p" 8 coucou				# patern
#valgrind --leak-check=full
 ./checker "-p" 8 coucou 3			# patern
#valgrind --leak-check=full
 ./checker "-p salut" 8 coucou 3		# patern
#valgrind --leak-check=full
 ./checker "-p salut 5" 8 coucou 3	# patern
#		help_only
#valgrind --leak-check=full
 ./checker -h							# help
#valgrind --leak-check=full
 ./checker -h 547						# help
#valgrind --leak-check=full
 ./checker -h 547 8					# help
#valgrind --leak-check=full
 ./checker -h "547"					# help
#valgrind --leak-check=full
 ./checker -h "547" "8"				# help
#valgrind --leak-check=full
 ./checker "-h 547" "8"				# help
#valgrind --leak-check=full
 ./checker "-h 547" 8					# help
#valgrind --leak-check=full
 ./checker "-h" 8 coucou				# help
#valgrind --leak-check=full
 ./checker "-h" 8 coucou 3			# help
#valgrind --leak-check=full
 ./checker "-h salut" 8 coucou 3		# help
#valgrind --leak-check=full
 ./checker "-h salut 5" 8 coucou 3	# help
#		help_only_pattern_mute
#valgrind --leak-check=full
 ./checker -hp						# help
#valgrind --leak-check=full
 ./checker -hp 547					# help
#valgrind --leak-check=full
 ./checker -hp 547 8					# help
#valgrind --leak-check=full
 ./checker -hp "547"					# help
#valgrind --leak-check=full
 ./checker -hp "547" "8"				# help
#valgrind --leak-check=full
 ./checker "-hp 547" "8"				# help
#valgrind --leak-check=full
 ./checker "-hp 547" 8				# help
#valgrind --leak-check=full
 ./checker "-hp" 8 coucou				# help
#valgrind --leak-check=full
 ./checker "-hp" 8 coucou 3			# help
#valgrind --leak-check=full
 ./checker "-hp salut" 8 coucou 3		# help
#valgrind --leak-check=full
 ./checker "-hp salut 5" 8 coucou 3	# help
#		help_only_pattern_mute_reverse
#valgrind --leak-check=full
 ./checker -ph						
#valgrind --leak-check=full
 ./checker -ph 547					# help
#valgrind --leak-check=full
 ./checker -ph 547 8					# help
#valgrind --leak-check=full
 ./checker -ph "547"					# help
#valgrind --leak-check=full
 ./checker -ph "547" "8"				# help
#valgrind --leak-check=full
 ./checker "-ph 547" "8"				# help
#valgrind --leak-check=full
 ./checker "-ph 547" 8				# help
#valgrind --leak-check=full
 ./checker "-ph" 8 coucou				# help
#valgrind --leak-check=full
 ./checker "-ph" 8 coucou 3			# help
#valgrind --leak-check=full
 ./checker "-ph salut" 8 coucou 3		# help
#valgrind --leak-check=full
 ./checker "-ph salut 5" 8 coucou 3	# help
#		file
#valgrind --leak-check=full
 ./checker -f							# name miss
#valgrind --leak-check=full
 ./checker -f 547						# not exist
#valgrind --leak-check=full
 ./checker -f 547 8					# not exist
#valgrind --leak-check=full
 ./checker -f "547"					# not exist
#valgrind --leak-check=full
 ./checker -f "547" "8"				# not exist
#valgrind --leak-check=full
 ./checker "-f 547" "8"				# not exist
#valgrind --leak-check=full
 ./checker "-f 547" 8					# not exist
#valgrind --leak-check=full
 ./checker "-f" 8 coucou				# not exist
#valgrind --leak-check=full
 ./checker "-f" 8 coucou 3			# not exist
#valgrind --leak-check=full
 ./checker "-f salut" 8 coucou 3		# not exist
#valgrind --leak-check=full
 ./checker "-f salut 5" 8 coucou 3	# not exist
touch file_1
#valgrind --leak-check=full
 ./checker "-f" file_1				# KO
#valgrind --leak-check=full
 ./checker "-f file_1"				# KO
#valgrind --leak-check=full
 ./checker -f file_1					# KO
#valgrind --leak-check=full
 ./checker "-f" file_1 42 -42			# OK
#valgrind --leak-check=full
 ./checker "-f file_1" 42 -42			# OK
#valgrind --leak-check=full
 ./checker "-f file_1 42" -42			# OK
#valgrind --leak-check=full
 ./checker "-f file_1 42 -42"			# OK
#valgrind --leak-check=full
 ./checker -f file_1 42 -42			# OK
#valgrind --leak-check=full
 ./checker "42" -f file_1 -42			# OK
#valgrind --leak-check=full
 ./checker "42 -f" file_1 -42			# OK
#valgrind --leak-check=full
 ./checker "42 -f file_1" -42			# OK
#valgrind --leak-check=full
 ./checker "42 -f file_1 -42"			# OK
#valgrind --leak-check=full
 ./checker 42 -f file_1 -42			# OK
#valgrind --leak-check=full
 ./checker "42" -42 -f file_1			# OK
#valgrind --leak-check=full
 ./checker "42 -42" -f file_1			# OK
#valgrind --leak-check=full
 ./checker "42 -42 -f" file_1			# OK
#valgrind --leak-check=full
 ./checker "42 -42 -f file_1"			# OK
#valgrind --leak-check=full
 ./checker 42 -42 -f file_1			# OK

#		edit
#valgrind --leak-check=full
 ./checker -e							# name miss
#valgrind --leak-check=full
 ./checker -e 547						# KO
#valgrind --leak-check=full
 ./checker -e "547"					# KO
#valgrind --leak-check=full
 ./checker -e 547 8					# OK
#valgrind --leak-check=full
 ./checker -e "547" "8"				# OK
#valgrind --leak-check=full
 ./checker "-e 547" "8"				# OK
#valgrind --leak-check=full
 ./checker "-e 547" 8					# OK
#valgrind --leak-check=full
 ./checker "-e" 8 coucou				# error
#valgrind --leak-check=full
 ./checker "-e" 8 coucou 3			# error
#valgrind --leak-check=full
 ./checker "-e salut" 8 coucou 3		# error
#valgrind --leak-check=full
 ./checker "-e salut 5" 8 coucou 3	# error

#valgrind --leak-check=full
 ./checker -e salut 1				    # OK
#valgrind --leak-check=full
 ./checker -e salut -f salut 11	    # OK
#valgrind --leak-check=full
 ./checker -ev salut				    # KO
#valgrind --leak-check=full
 ./checker -e salut -f salut		    # KO
#valgrind --leak-check=full
 ./checker -e -f					    # edit name miss
#valgrind --leak-check=full
 ./checker -e salut -f			    # file name miss
#valgrind --leak-check=full
 ./checker -ef salut				    # illegal option
#valgrind --leak-check=full
 ./checker -ew salut				    # illegal option
#valgrind --leak-check=full
 ./checker -e salut w				    # Error
#valgrind --leak-check=full
 ./checker -e salut 1 -v			    # Error
#valgrind --leak-check=full
 ./checker -ep salut				    # patern
#valgrind --leak-check=full
 ./checker -eph salut				    # help
#valgrind --leak-check=full
 ./checker 1 2 3				        # OK
#valgrind --leak-check=full
 ./checker 1 2 1				        # KO




rm salut
rm file_1
rm 547 8