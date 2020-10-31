module Turing where

import Data.Foldable (toList)
import qualified Data.List as L
import qualified Data.Sequence as Seq
import  Data.Sequence (Seq, (<|), (|>), ViewL (..), ViewR(..))

-- Types
type State = Int
type Sym = Char

-- Datatypes
data Dir = MLeft | MRight
data TConf = TConf {
  symLeft :: Seq Sym,
  symCurr :: Maybe Sym,
  symRight :: Seq Sym
}
data MConf = MConf {
  stateCurr :: State,
  tConf :: TConf
}
data TuringMachine = TuringMachine {
  delta :: State -> Maybe Sym -> (State, Sym, Dir),
  start, accept, reject :: State
}

run :: TuringMachine -> [Sym] -> [MConf]
run m = headBreak (mValidate m) . iterate (transMConf m) . mInit m 
  where
    headBreak y xs = let (p,r) = break y xs in p ++ [head r]

mValidate :: TuringMachine -> MConf -> Bool
mValidate m (MConf {stateCurr = s}) = (s == accept m) || (s == reject m) 

transMConf :: TuringMachine -> MConf -> MConf
transMConf m (MConf s t) = let (nState, nSym, dir) = delta m s (symCurr t) in MConf nState (transTConf t nSym dir)

transTConf :: TConf -> Sym -> Dir -> TConf
transTConf (TConf l _ r) s MLeft = case Seq.viewr l of EmptyR -> TConf Seq.empty Nothing right
                                                       lInit :> lLast -> TConf lInit (Just lLast) right
  where right = s <| r
transTConf (TConf l _ r) s MRight = case Seq.viewl r of EmptyL -> TConf left Nothing Seq.empty
                                                        rHead :< rTail -> TConf left (Just rHead) rTail
  where left = l |> s

tInit :: [Sym] -> TConf
tInit (x:xs) = TConf Seq.empty (Just x) (Seq.fromList xs)
tInit [] = TConf Seq.empty Nothing Seq.empty

mInit :: TuringMachine -> [Sym] -> MConf
mInit m t = MConf (start m) (tInit t)

