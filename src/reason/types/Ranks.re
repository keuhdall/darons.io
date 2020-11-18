type t =
  | UltimateBoomer
  | Boomer
  | AspirantDaron
  | YoungGranpa
  | TimidlyOld
  | DegenerateMillenial;

let getRank = score => {
  let percentage = score /. Js.Int.toFloat(List.length(Questions.all)) *. 100.0;
  Js.log("percentage is : " ++ Js.Float.toString(percentage))
  switch percentage {
  | x when x >= 90.0 => UltimateBoomer
  | x when x >= 75.0 => Boomer
  | x when x >= 60.0 => AspirantDaron
  | x when x >= 45.0 => YoungGranpa
  | x when x >= 30.0 => TimidlyOld
  | _ => DegenerateMillenial
  };
};

let getRankName = rank => {
  switch rank {
  | UltimateBoomer        => {j|Ultimate Boomer|j}
  | Boomer                => {j|Boomer|j}
  | AspirantDaron         => {j|Aspirant Daron|j}
  | YoungGranpa           => {j|Jeune Pépère|j}
  | TimidlyOld            => {j|Timidement Vieux|j}
  | DegenerateMillenial   => {j|Millénial Dégénéré|j}
  };
};

let getDescription = rank => {
  switch rank {
  | UltimateBoomer =>
    {j|
    Bravo, tu es l'Ultimate Boomer.
    Tu écoutes déjà très probablement du Maurice Chevalier sur un vieux tourne disque,
    et tu participes à toutes les réunions du syndic de ton immeuble.
    |j}
  | Boomer =>
    {j|
    Ton processus de Daronisation était terminé,
    mais tu as voulu aller plus loin. Non content d'être un Daron, tu as voulu devenir un Boomer.
    Si tu as moins de 25 ans c'est inquiétant.
    |j}
  | AspirantDaron =>
    {j|
    Ton processus de Daronisation est bien entamé, mais pas tout à fait terminé,
    encore quelques années et tu auras le pavillon en banlieu le chien et le monospace,
    courage tu y est presque !
    |j}
  | YoungGranpa =>
    {j|
    Tu as déjà pris goût aux soirées tisanes triominos, même si tout ton entourage n'est pas au courant.
    Tu n'es pas loin de franchir le point de non retour.
    |j}
  | TimidlyOld =>
    {j|
    Tu vis dans le déni et essaie de te persuader que tu es encore capable de vivre comme un jeune,
    mais ce n'est qu'une fuite en avant pour échapper à l'appel des pantoufles et de la sieste.
    |j}
  | DegenerateMillenial =>
    {j|
    Ce test ne t'est vraisemblablement pas destiné,
    reviens ici l'an prochain. Il s'agirait de grandir.
    |j}
  };
};