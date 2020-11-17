namespace Tennis

(*
0 - 15 - 30 - 40
Si 40/40 => deuce => il faut 2 points d'écart.

*)

type Point =
    | Zero
    | Quinze
    | Trente


type Points = {
    P1: Point
    P2: Point
}
type Joueur =
    | P1
    | P2


type Quarante = {
    JoueurAQuarante: Joueur
    PointsAutreJoueur: Point
}

type Score = 
    | Points of Points 
    | Quarante of Quarante
    | Deuce
    | Avantage of Joueur
    | Victoire of Joueur

module Score =
    let FromDeuce gagnant = Avantage gagnant


    let FromVictoire victorieux gagnant = Victoire victorieux

    let FromAvantage avantagé gagnant = 
        if avantagé = gagnant then 
            Victoire avantagé 
        else 
            Deuce

    let FromQuarante quarante gagnant = 
        if quarante.JoueurAQuarante = gagnant then
            Victoire gagnant
        else
            match quarante.PointsAutreJoueur with 
            | Zero -> Quarante {quarante with PointsAutreJoueur = Quinze}
            | Quinze -> Quarante {quarante with PointsAutreJoueur = Trente}
            | Trente -> Deuce

    let FromPoints p gagnant =
        let getPointsAutreJoueur p joueur = 
            match joueur with
            | P1 -> p.P2
            | P2 -> p.P1

        let getPoint points joueur = 
            match joueur with
            | P1 -> points.P1
            | P2 -> points.P2

        let Incrementer point = 
            match point with
            | Zero -> Some Quinze
            | Quinze -> Some Trente
            | Trente -> None

        let setPointGagnant p joueur score =
            match Incrementer score with
            | None -> Quarante { JoueurAQuarante = joueur; PointsAutreJoueur = getPointsAutreJoueur p gagnant }
            | Some nouveauPoint->
                match joueur with 
                | P1 -> Points { p with P1 = nouveauPoint}
                | P2 -> Points { p with P2 = nouveauPoint}

        let scoreGagnant = getPoint p gagnant

        setPointGagnant p gagnant scoreGagnant

    let MarquerScoreJoueur score gagnant =
        match score with
        | Deuce -> FromDeuce gagnant
        | Avantage avantagé -> FromAvantage avantagé gagnant
        | Victoire victorieux -> FromVictoire victorieux gagnant
        | Quarante quarante -> FromQuarante quarante gagnant
        | Points points -> FromPoints points gagnant

    let MarquerScoreJoueur' =
        function
        | Deuce -> FromDeuce 
        | Avantage avantagé -> FromAvantage avantagé 
        | Victoire victorieux -> FromVictoire victorieux 
        | Quarante quarante -> FromQuarante quarante 
        | Points points -> FromPoints points 

    let ScoreJoueurs gagnants =
        gagnants |> List.fold MarquerScoreJoueur (Points {P1 = Zero; P2 = Zero})
        
    let ScoreJoueur' gagnants =
        let rec ScoreJoueurRec gagnants score = 
            match gagnants with
            | [] -> score
            | gagnant::autresGagnants -> 
                let nouveauScore = MarquerScoreJoueur score gagnant
                ScoreJoueurRec autresGagnants nouveauScore

        ScoreJoueurRec gagnants (Points {P1 = Zero; P2 = Zero})
