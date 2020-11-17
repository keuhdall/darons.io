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
  | x when x >= 65.0 => AspirantDaron
  | x when x >= 50.0 => YoungGranpa
  | x when x >= 35.0 => TimidlyOld
  | _ => DegenerateMillenial
  };
};

let getRankName = rank => {
  switch rank {
  | UltimateBoomer => "Ultimate Boomer"
  | Boomer => "Boomer"
  | AspirantDaron => "Apirant Daron"
  | YoungGranpa => {j|Jeune Pépère|j}
  | TimidlyOld => "Timidement Vieux"
  | DegenerateMillenial => {j|Millénial Dégénéré|j}
  };
};

let getDescription = rank => {
  switch rank {
  | UltimateBoomer =>
    {j|Bravo, tu es l'Ultimate Boomer. Tu écoutes déjà très probablement du Maurice Chevalier sur un vieux tourne disque, et tu participes à toutes les réunions du syndic de ton immeuble|j}
  | Boomer =>
    {j|Ton processus de Daronisation était terminé, mais tu as voulu aller plus loin. Non content d'être un Daron, tu as voulu devenir un Boomer. Si tu as moins de 25 ans c'est inquiétant.|j}
  | AspirantDaron       =>
    {j|Ton processus de Daronisation est bien entamé, mais pas tout à fait terminé, encore quelques années et tu auras le pavillon en banlieu le chien et le monospace, courage tu y est presque !|j}
  | YoungGranpa         =>
    {j|[Jeune pépère]|j}
  | TimidlyOld          =>
    {j|[Timidement vieux]|j}
  | DegenerateMillenial =>
    {j|[Millenial dégénéré]|j}
  };
};