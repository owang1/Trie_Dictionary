Group Members: Olivia Wang and Yejee Oh

Project Instructions:

The C++ code may be executed by typing "make" to execute the Makefile.
To get word percentage results for a movie script, type in the command
"./frequencies [filename.txt]". Note that multiple movie scripts can
be run at a time. For instance, to get the output for the 8 movies:

./frequencies finding_nemo.txt shrek.txt the_kings_speech.txt the_imitation_game.txt
white_checks.txt grown_ups.txt star_wars.txt the_martian.txt

You can also see the results in frequencies.txt.

Benchmarking was done by executing the map_bench.cpp. More information
is given in the runtime.txt document. Basically, the map_bench.cpp
inserts the words from the first text file specified, and searches 
the second text file specified. We ran tests for 6 letter words that were
randomly generated to see the greater speed with which words with a common
prefix are inserted.

You may execute using the pattern like "./map_bench pre_#.txt insert_#.txt"
example: ./map_bench pre_10.txt insert_10.txt

For the python notebook component, run
jupyter notebook --ip student01.cse.nd.edu --port 9111 --no-browser

on student01 (or change it if you are in another student machine). It will output
a url and you can paste it into the browser and interact with the interface.

Participation: 
Yejee 10/10
Olivia 10/10
