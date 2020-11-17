
type answer = Yes | No;

type question = {
  content: string,
  coef: float
};

let all = [
  // Soirées
  {content: {j|Arrivée minuit en soirée, tu te dis que tu vas bientôt rentrer te coucher ?|j},  coef: 1.0},
  {content: {j|Ta résistance à l’alcool diminue-t-elle avec le temps qui passe ?|j},            coef: 1.0},
  {content: {j|Est-ce que tu bois plus de vin et moins d’alcool fort qu’auparavant ?|j},        coef: 1.0},
  {content: {j|Est-ce que tes cuites sont encore plus dures à cuver qu’avant ?|j},              coef: 1.0},
  {content: {j|As-tu déjà appelé la police pour tapage nocturne ?|j},                           coef: 1.0},
  {content: {j|Tu préfères les places assises aux places debout en concert ?|j},                coef: 1.0},
  {content: {j|Est-ce que tu mets des bouchons d'oreilles en concert ?|j},                      coef: 1.0},

  // Finances
  {content: {j|Est-ce que tu t’arrêtes devant les agences immobilières pour regarder les prix en vitrine ?|j},          coef: 1.0},
  {content: {j|As-tu pensé à acheter des actions pour des investissements futurs ?|j},                                  coef: 1.0},
  {content: {j|As-tu investi dans des actions ?|j},                                                                     coef: 1.0},
  {content: {j|As-tu déjà parler sérieusement de PEL/PEA et autres taux d’intérêt bancaires avec tes amis ?|j},         coef: 1.0},
  {content: {j|Est-ce que tu comprends tes papiers de mutuelle/assurance ?|j},                                          coef: 1.0},
  {content: {j|Ton livret livret jeune a-t-il été cloturé à la banque ?|j},                                             coef: 1.0},
  {content: {j|Est-ce que tu relis tous les mois ton loyer ou ta fiche de paie pour voir si ça a bougé ?|j},            coef: 1.0},
  {content: {j|Est-ce que tes rendez-vous avec ton conseiller banquaire sont à ton initiative plus qu'à la sienne ?|j}, coef: 1.0},

  // Santé
  {content: {j|As-tu un stock de médicaments dans ta salle de bain/pharmacie ?|j},          coef: 1.0},
  {content: {j|As-tu arrêté de fumer pour toi/lui/elle ?|j},                                coef: 1.0},
  {content: {j|Est-ce que tu fais la sieste à nouveau ?|j},                                 coef: 1.0},
  {content: {j|Arrives-tu encore à faire des grasses matinées ?|j},                         coef: 1.0},
  {content: {j|Est-ce que tu galères plus qu’avant lorsqu’il s’agit de faire du sport ?|j}, coef: 1.0},
  {content: {j|Est-ce que tu perds tes cheveux ?|j},                                        coef: 1.0},
  {content: {j|Est-ce que ta vision a baissée au point de porter des lunettes ?|j},         coef: 1.0},
  {content: {j|Est-ce que tu aimes te coucher tôt pour être en forme le lendemain ?|j},     coef: 1.0},
  {content: {j|Est-ce que tu as pris du bide qui ne veut plus partir ?|j},                  coef: 1.0},
  {content: {j|As-tu investi dans un tapis de course ou vélo d'appartement ?|j},            coef: 1.0},

  // Social
  {content: {j|Est-ce que tu te vantes de tes performances sportives sur les réseaux sociaux ?|j},                            coef: 1.0},
  {content: {j|Est-ce que tu parles souvent de la météo dans tes conversations ?|j},                                          coef: 1.0},
  {content: {j|Est-ce que tu appelles les jeunes, « les jeunes » ?|j},                                                        coef: 1.0},
  {content: {j|Es-tu déjà nostalgique du lycée ou de la fac ?|j},                                                             coef: 1.0},
  {content: {j|Est-ce que tu vas moins sur les réseaux sociaux qu’avant ?|j},                                                 coef: 1.0},
  {content: {j|As-tu accepté qu’on t’appelle Mr/Mme sans que ça te fasse quoique ce soit ?|j},                                coef: 1.0},
  {content: {j|Est-ce que tu ne comprends pas certains mots employés par des gens plus jeune que toi ?|j},                    coef: 1.0},
  {content: {j|As-tu des amis de ton âge qui commencent à parler des enfants/avoir des enfants ?|j},                          coef: 1.0},
  {content: {j|As-tu été invité au marriage de quelqu'un de ton âge ?|j},                                                     coef: 1.0},
  {content: {j|Est-ce qu'un de tes amis (ou toi même) est parti vivre à l'étranger ?|j},                                      coef: 1.0},
  {content: {j|Est-ce qu'il t'arrive de dire dans une conversation : "ah je connais j'ai un pote qui bosse là dedans ..."|j}, coef: 1.0},
  {content: {j|Est-ce que l'impolitesse t'énerve plus qu'avant ? (gestes, paroles...)|j},                                     coef: 1.0},
  {content: {j|Est-ce que tu cherches à t'installer avec ton homme/ta femme ?|j},                                             coef: 1.0},

  // Courses
  {content: {j|Est-ce que tu réalises une liste de courses avant d’aller au supermarché ?|j}, coef: 1.0},
  {content: {j|Est-ce que tu prends un cadis quand tu fais tes courses ?|j},                  coef: 1.0},
  {content: {j|Est-ce que tu réutilises tes sacs plastiques quand tu fais tes courses ?|j},   coef: 1.0},
  {content: {j|Est-ce que tu as un cabas ou un charriot à roulettes ?|j},                     coef: 1.0},
  {content: {j|Est-ce que tu vas au marché ?|j},                                              coef: 1.0},
  {content: {j|Est-ce que tu collectionnes les bons de réduction ?|j},                        coef: 1.0},
  {content: {j|Es-tu enthousiaste à l'idée d'acheter un nouvel aspirateur ?|j},               coef: 1.0},
  {content: {j|Est-ce que tu participes à la foire aux vins dans les grandes surfaces ?|j},   coef: 1.0},
  {content: {j|Est-ce que tu relis ton ticket de course, pour vérifier au cas ou ?|j},        coef: 1.0},

  // Alimentaire
  {content: {j|Est-ce que tu cuisines en avance pour plusieurs jours dans la semaine ?|j},                coef: 1.0},
  {content: {j|Est-ce que tu programmes tes repas pour la semaine ?|j},                                   coef: 1.0},
  {content: {j|Est-ce que ça fait plus de 6 mois que tu n'as pas mangé un kebab ?|j},                     coef: 1.0},
  {content: {j|Est-ce que tu vas plus souvent au restaurant qu'au fast-food ?|j},                         coef: 1.0},
  {content: {j|Est-ce que tu rêves d'avoir ton propre potager bio ?|j},                                   coef: 1.0},
  {content: {j|Est-ce que tu commences à acheter de bonnes bouteilles ? (Cognac, Whiskey, Vins ....)|j},  coef: 1.0},
  {content: {j|Est-ce tu essaies de suivre un régime alimentaire équilibré ?|j},                          coef: 1.0},
  {content: {j|Est-ce que tu préfères le chocolat noir aux autres chocolats ?|j},                         coef: 1.0},
  {content: {j|Est-ce que tu trouves les bonbons de ton enfance trop sucrés ?|j},                         coef: 1.0},
  {content: {j|Est-ce que le bac à bières de ton frigo est devenu un bac à légumes ?|j},                  coef: 1.0},

  // Quotidien
  {content: {j|Est-ce que tu réalises des to-do list pour ne rien oublier ?|j},                                       coef: 1.0},
  {content: {j|Est-ce que tu relèves ta boîte aux lettres tous les jours ?|j},                                        coef: 1.0},
  {content: {j|As-tu encore le droit aux réductions pour étudiant ?|j},                                               coef: 1.0},
  {content: {j|Est-ce que tu collectionnes les souvenirs de vacances (cartes postales, magnets, boule à neige) ?|j},  coef: 1.0},
  {content: {j|Est-ce que tu passes plus de temps au téléphone avec les services clients ?|j},                        coef: 1.0},
  {content: {j|Est-ce que tu commates devant les émissions de TV que tu trouvais débiles ?|j},                        coef: 1.0},
  {content: {j|As-tu déjà changé un pneu sur ta voiture / ou changer les ampoules ?|j},                               coef: 1.0},
  {content: {j|As-tu déjà fais des travaux dans ton appartement ?|j},                                                 coef: 1.0},
  {content: {j|Est-ce que tu nettoies quand des invités viennent te rendre visite ?|j},                               coef: 1.0},
  {content: {j|Est-ce que tu as adopté un chien/chat parce que maintenant tu es posé ?|j},                            coef: 1.0},
  {content: {j|Est-ce le SUV te botte plus que la voiture de sport ?|j},                                              coef: 1.0},
  {content: {j|Est-ce que tu gueules devant ta TV quand tu regardes le journal de 20h ?|j},                           coef: 1.0},
  {content: {j|Est-ce que tu lis le journal plus qu'auparavant ?|j},                                                  coef: 1.0},
  {content: {j|Est-ce que tu as des pantoufles ?|j},                                                                  coef: 1.0},
  {content: {j|Est-ce que tu scroll pour trouver ta date de naissance sur les sites internet ?|j},                    coef: 1.0},
  {content: {j|Est-ce que tu prends des bains pour te détendre ?|j},                                                  coef: 1.0},
  {content: {j|Est-ce que tes musiques préférées passent sur Nostalgie ?|j},                                          coef: 1.0},
  {content: {j|Est-ce que tu connais par coeur des tubes des annnées 80 ? (Indochine, Sardou, ...)|j},                coef: 1.0},
  {content: {j|Est-ce que tu cherches des meubles sur Le Bon Coin ?|j},                                               coef: 1.0},
  {content: {j|Est-ce que tu te mets à collectionner des trucs inutiles ? (capsules, pin's, timbres...)|j},           coef: 1.0},
  {content: {j|Est-ce qu'il t'arrive de vouloir passer ton après-midi à lire dans un fauteuil/canapé ?|j},            coef: 1.0},
  {content: {j|Est-ce que tu es déprimé à l'approche de ton anniversaire ?|j},                                        coef: 1.0},
  {content: {j|Est-ce que tu te mets de profil devant le mirroir pour constater les dégats ?|j},                      coef: 1.0}
];