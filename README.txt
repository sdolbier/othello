As a solo group member, I did all the stuff the past 2 weeks.

I implemented a weighted scoring system for all the possible moves that my AI could make.
First, my AI looks at all the moves it could make, and the board state after those moves.
It calculates a score for how much it is winning or losing by after that move.
It then weights that score based on board position.
Since corners cannot be captured, and edges can only be captured by other edges,
these positions have a +5, etc, added on to their scores to make them more valuable.
Additionally, pieces that give corner access to the opponent are negatively weighted, and
pieces that give access to edge spaces are also negatively weighted.
This means my AI is making smarter decisions about which positions to place the piece
and has a sort of long-term thinking strategy going on game-wise. Hopefully this means I
can beat some simple AI's such as ones that play randomly or use a poorer weighting system.