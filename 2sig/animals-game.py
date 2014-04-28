#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-

"""
Written by Christian Stigen Larsen, http://csl.sublevel3.org
Placed in the public domain by the author

This is a version of the classic game of guessing which animal you
are thinking about.  It uses a binary tree to guess.

This code was originally part of a guest lecture I held in 2010
at the University of Stavanger, Norway.

The objective was to have students modify this program so that it
would use pickle to save the game data to disk.

The task text was this (translated to English):

Use pickle to save questions to disk, so they won't go away when
the program exits.

Intro to pickle:
>>> import pickle
>>> help(pickle)

Pickle/unpickle to/from a string:
>>> pickle.dumps("hello")
"S'hello'\np0\n."
>>> pickle.loads("S'hello'\np0\n.")
'hello'

Use pickle.dump(object, file) to save to disk, and pickle.load(file)
to load from disk.

Start by saving objects to disk in the function makeNewQuestion().
Next, try adding pickle code in the program startup to load the
questions from disk.  If the file does not exist, you should use
the default questions.
"""

import sys

def definiteNoun(s):
  "Add definite form to a noune, for instance 'whale' becomes 'a whale'"
  s = s.lower().strip()
  if s in ['a', 'e', 'i', 'o', 'u', 'y']:
    return "an " + s
  else:
    return "a " + s

def removeArticle(s):
  "Remove the definite article 'a' or 'an' from a noun."
  s = s.lower().strip()
  if s[0:3] == "an ": return s[3:]
  if s[0:2] == "a ": return s[2:]
  return s

def makeQuestion(question, yes, no):
  return [question, yes, no]

def isQuestion(p):
  "Check if node is a question (with answers), or a plain answer."
  return type(p).__name__ == "list"

def askQuestion(question):
  print "\r%s " % question,
  return sys.stdin.readline().strip().lower()

def getAnswer(question):
  if isQuestion(question):
    return askQuestion(question[0])
  else:
    return askQuestion("Were you thinking about %s?" % definiteNoun(question))

def answeredYes(answer):
  if len(answer) > 0:
    return answer.lower()[0] == "y"
  return False

def gameOver(message):
  global tries
  print ""
  print "\r%s" % message
  print "I used", tries, "questions!"
  print ""

def playAgain():
  return answeredYes(askQuestion("Do you want to play again?"))

def correctGuess(message):
  global tries
  gameOver(message)

  if playAgain():
    print ""
    tries = 0
    return Q
  else:
    sys.exit(0)

def nextQuestion(question, answer):
  global tries
  tries += 1

  if isQuestion(question):
    if answer:
      return question[1]
    else:
      return question[2]
  else:
    if answer:
      return correctGuess("I knew it!")
    else:
      return makeNewQuestion(question)

def replaceAnswer(tree, find, replace):
  if not isQuestion(tree):
    if tree == find:
      return replace
    else:
      return tree
  else:
    return makeQuestion(tree[0],
      replaceAnswer(tree[1], find, replace),
      replaceAnswer(tree[2], find, replace))

def makeNewQuestion(wrongAnimal):
  global Q, tries

  correctAnimal = removeArticle(askQuestion("I give up.  What did you think about?"))

  newQuestion = askQuestion("Enter a question that would distinguish %s from %s:"
      % (definiteNoun(correctAnimal), definiteNoun(wrongAnimal))).capitalize()

  yesAnswer = answeredYes(askQuestion("If I asked you this question " +
    "and you thought about %s, what would the correct answer be?" % definiteNoun(correctAnimal)))

  # Create new question node
  if yesAnswer:
    q = makeQuestion(newQuestion, correctAnimal, wrongAnimal)
  else:
    q = makeQuestion(newQuestion, wrongAnimal, correctAnimal)

  # Create new question tree and start over again
  Q = replaceAnswer(Q, wrongAnimal, q)
  tries = 0 # reset since we'll play again
  return Q

tries = 0
Q = (makeQuestion('Can if fly?', 'pelican', 'whale'))
q = Q

print "Imagine an animal.  I will try to guess which one."
print "You are only allowed to answer YES or NO."
print ""

try:
  while True:
    ans = answeredYes(getAnswer(q))
    q = nextQuestion(q, ans)
except KeyboardInterrupt:
  sys.exit(0)
except Exception, e:
  print e
  sys.exit(1)
