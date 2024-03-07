#!/usr/bin/ruby
# Examples: alias sudoku=./sudoku.rb
# sudoku test now <= infering 'test', puts default values into the test file
# sudoku test hard <= puts default values except the hard level
# sudoku test hard 55 min <= puts default date and time plus hard level, 55 finishing time and minutes 'min' label.
#
#
# A proper example would be:
#   
#   sudoku medium 50 mins
#
# which will put the current date and time plus mentioned level and finishing time
# in the sudoku.stat file created in the user home directory.

SUDOKU_FILE_PATH = File.expand_path("~/sudoku.stat")
PSEUDO_FILE_PATH = File.expand_path("~/sudoku_test.stat")

DATE_REGEX = /^[0]{0,1}[0-9]{0,1}\/[01]{0,1}[0-9]{0,1}\/[0-9]{4}$/
DEFAULT_DATE = Time.now.strftime("%d/%m/%Y")

TIME_REGEX = /^\d{1,2}:\d{1,2}$/
DEFAULT_TIME = Time.now.strftime("%H:%M")

LEVEL_REGEX = /^(easy|hard|medium|very-hard)$/
DEFAULT_LEVEL = "easy"

FINISHING_TIME_REGEX = /^\d{1,3}$/
DEFAULT_FINISHING_TIME = -> { 
  fts = File.readlines(SUDOKU_FILE_PATH).collect {
    |x|
    x.strip.split(' ').select {
      |y|
      y=~FINISHING_TIME_REGEX
    }.first.to_i
  }
  return (fts.sum.to_f/fts.length).round
}.call
#puts("DEFAULT_FINISHING_TIME: #{DEFAULT_FINISHING_TIME}")

MIN_LABEL_REGEX = /^mins{0,1}$/
DEFAULT_MIN_LABEL = "min"

PARSER_DATA = {
  date: [ DATE_REGEX, DEFAULT_DATE ],
  time: [ TIME_REGEX, DEFAULT_TIME ],
  level: [ LEVEL_REGEX, DEFAULT_LEVEL ],
  finishing_time: [ FINISHING_TIME_REGEX, DEFAULT_FINISHING_TIME ],
  min_label: [ MIN_LABEL_REGEX, DEFAULT_MIN_LABEL ]
}


# Parses a string containing any value plus
# "date time level finishing-time minutes-label"
# 
# Scans only the needed values from the string
# and returns as hash mapping as keys formerly
# described and keys are relevent symbols!
def parse(string, sep=' ')
  regexes = PARSER_DATA.to_a.collect{|x| [ x[0], x[1][0] ]}.to_h
  parsed_data = PARSER_DATA.to_a.collect{|x| [ x[0], x[1][1] ]}.to_h

  if string.class == String then
    string = string.split(' ').collect{|x| x.strip}
  end

  string.each do |str|
    regexes.keys.each do |reg_key|
      if str=~regexes[reg_key] then
        parsed_data[reg_key] = str
      end
    end
  end

  return parsed_data
end

def format_stat(parsed_data)
  # the format they are defined they go!
  return PARSER_DATA.keys.collect{|x| parsed_data[x]}.join(' ')
end

if $0 == __FILE__ then
  file_path = ARGV[0]=~/test/ ? PSEUDO_FILE_PATH : SUDOKU_FILE_PATH
  sudoku_stat = format_stat(parse(ARGV))
  command = %[echo "#{sudoku_stat}" >> "#{file_path}"]
  puts(command)
  `#{command}`
end

