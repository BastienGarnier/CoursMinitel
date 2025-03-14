\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{minitelreport}[2024/11/13 Minitel Report Class]

\LoadClass[french]{report}
	\setcounter{secnumdepth}{4}

% Utilitaire LaTeX
\RequirePackage{etoolbox}
\RequirePackage{ifthen}

\RequirePackage[top=3cm, bottom=3cm, left=3cm, right=3cm]{geometry}

% Caractères et symboles de texte (+ csquotes après minted pour éviter un warning)
	\RequirePackage{lmodern}
	\RequirePackage[T1]{fontenc}
	\RequirePackage[french]{babel}
	\RequirePackage{hyphenat}
	\RequirePackage{textcomp}
	\RequirePackage[normalem]{ulem}
	\RequirePackage{pifont}

%%%%%%%%%%%%%%
% Graphismes %
%%%%%%%%%%%%%%

% Ben tikz... pas besoin d'épiloguer
\RequirePackage{tikz}

% Couleurs de Minitel
\RequirePackage[table, dvipsnames]{xcolor}
	\definecolor{minitelgreen1}{rgb}{0.56, 0.75, 0.07}
	\definecolor{minitelgreen3}{rgb}{0.0, 0.5, 0.0}
	\definecolor{minitelgreen2}{rgb}{0.29, 0.63, 0.004}
	\definecolor{minitelgreen4}{rgb}{0.93, 0.96, 0.84}

% Images et SVG
\RequirePackage{graphicx}
\RequirePackage{svg}

% Ornementations
\RequirePackage{pgfornament-han}

%%%%%%%%%
% Maths %
%%%%%%%%%

\RequirePackage{amssymb}
\RequirePackage{amsmath}
\RequirePackage{bbm}
\RequirePackage{stmaryrd}

%%%%%%%%%%%%%%%%
% Informatique %
%%%%%%%%%%%%%%%%

% Pour les algorithmes
\RequirePackage[lined,boxed,commentsnumbered, ruled,vlined,linesnumbered, french]{algorithm2e}
	\SetKwComment{Comment}{/* }{ */}
	\SetKwInput{kwQuand}{Quand}

% Pour les arborescences de fichiers
\RequirePackage{forest}
	\forestset{default preamble={for tree={
			font=\ttfamily,
			grow'=0,
			child anchor=west,
			parent anchor=south,
			anchor=west,
			calign=first,
			edge path={
				\noexpand\path [draw, \forestoption{edge}]
				(!u.south west) +(7.5pt,0) |- node[fill,inner sep=1.25pt] {} (.child anchor)\forestoption{edge label};
			},
			before typesetting nodes={
				if n=1
					{insert before={[,phantom]}}
					{}
			},
			fit=band,
			before computing xy={l=15pt},
		}}
	}

% Pour surtitrer et référencer les codes
\RequirePackage{listings}

% Pour les échantillons de codes colorés syntaxiquement
\RequirePackage[newfloat]{minted2}
	\definecolor{mintedsourcebackground}{rgb}{0.97,0.97,0.97}
	\definecolor{mintedterminalbackground}{rgb}{0., 0., 0.}
	\setminted[c]{
		bgcolor=mintedsourcebackground,
		frame=leftline,
		framerule=0.4pt,
		framesep=2mm,
		tabsize=2,
		obeytabs=true,
		linenos=true,
		numberblanklines=true,
		numbersep=5pt,
		fontfamily=tt,
		fontsize=\small
	}

	\setminted[nasm]{
		bgcolor=mintedsourcebackground,
		frame=leftline,
		framerule=0.4pt,
		framesep=2mm,
		tabsize=2,
		obeytabs=true,
		linenos=true,
		numberblanklines=true,
		numbersep=5pt,
		fontfamily=tt,
		fontsize=\small
	}

	\setminted[make]{
		bgcolor=mintedsourcebackground,
		frame=leftline,
		framerule=0.4pt,
		framesep=2mm,
		tabsize=2,
		obeytabs=true,
		linenos=true,
		numberblanklines=true,
		numbersep=5pt,
		fontfamily=tt,
		fontsize=\small
	}

	\setminted[bash]{
		frame=single,
		obeytabs=false,
		linenos=false,
		fontfamily=tt,
		fontsize=\small,
	}

\RequirePackage{csquotes}

%%%%%%%%%%%%%%%%
% Mise en page %
%%%%%%%%%%%%%%%%
\RequirePackage{tocloft}

\makeatletter
	\newcommand\HUGE{\@setfontsize\Huge{50}{60}}
\makeatother

\RequirePackage{fancyhdr}
	\setlength{\headheight}{15.2pt}
	\pagestyle{fancyplain}
	\fancyhf{}
	\makeatletter
	\lhead{ \fancyplain{}{\@title : \@subtitle} }
	\makeatother
	\rhead{ \fancyplain{}{\rightmark} }
	\rfoot{ \fancyplain{}{\thepage} }

% Jolies sections
\RequirePackage{titlesec}
\newcommand{\marginsecnumber}[1]{%
  \makebox[0pt][r]{#1\hspace{6pt}}%
}

\newcommand{\makeornament}[1]{
	\rlap{\pgfornamenthan[ydelta=-25pt, height=.75cm, color=minitelgreen2]{9}}\pgfornamenthan[ydelta=10pt, symmetry=h, height=.75cm, color=minitelgreen2]{9}
	~#1\unskip~
	\pgfornamenthan[ydelta=-25pt, height=.75cm, symmetry=v, color=minitelgreen2]{9}\llap{\pgfornamenthan[ydelta=10pt, symmetry=c, height=.75cm, color=minitelgreen2]{9}}
}

	\titleformat{\part}[block]
	{\centering}
	{\huge Partie \thepart\\}
	{0pt}
	{\HUGE\scshape}

	\titleformat{\section}[block]
	{\centering}
	{}
	{0pt}
	{\huge\scshape\protect\makeornament}

	\titleformat{\subsection}
  {\normalfont\large\bfseries}
  {\color{minitelgreen3}\marginsecnumber\thesubsection}
  {0pt}
  {\color{minitelgreen3}\Large\bfseries}

  \titleformat{\subsubsection}
  {\normalfont\bfseries}
  {}
  {0pt}
  {\color{minitelgreen3}\normalfont\bfseries}

% Jolis chapitres
\RequirePackage[Rejne]{fncychap}

% Extension pour la gestion des paragraphes
\RequirePackage[skip=10pt plus1pt, indent=0pt]{parskip}

% Extension pour les tabulations et espaces
\RequirePackage{tabto}

% Meilleur gestion des alignements
\RequirePackage{ragged2e}

% Faire des jolis boîtes
\RequirePackage{tcolorbox}
	\newtcolorbox{minitelbasicbox}[2][]
	{
	  colframe = minitelgreen3,
	  colback  = minitelgreen1!30!white,
	  coltitle = white,  
	  title    = {#2},
	  #1,
	}

% Pour multiplier les options d'énumération de type itemize ou enumerate
\RequirePackage[shortlabels]{enumitem}
	\setlist[itemize, 1]{font=\color{minitelgreen3}, label=\ding{110}}
	\setlist[itemize, 2]{font=\color{minitelgreen2}, label=\textbullet}
	\setlist[itemize, 3]{font=\color{minitelgreen1}, label=\ding{117}}

% Page de garde
\makeatletter
\newcommand\variant[1]{\renewcommand\@variant{Version #1}}
\newcommand\@variant{}
\newcommand\subtitle[1]{\renewcommand\@subtitle{#1}}
\newcommand\@subtitle{}
\newcommand\licence[1]{\renewcommand\@licence{#1}}
\newcommand\@licence{}
\renewcommand{\maketitle}{
	\begin{tikzpicture}[remember picture,overlay]
        \node[xshift=-108mm, yshift=151.5mm] at (current page.center)
        {%
            \begin{tikzpicture}[remember picture,overlay]
			    \node [shading = axis,rectangle, left color=minitelgreen1, right color=minitelgreen3,shading angle=-135, anchor=north, minimum width=\paperwidth, minimum height=\paperheight] (box) at (current page.north){};
			  \end{tikzpicture}
        };
    \end{tikzpicture}
    \color{white}
	\pagenumbering{gobble}
	\begin{minipage}{0.5\textwidth}
	\large
	\textbf{\@date}
	\end{minipage}
	\begin{minipage}{0.5\textwidth}
	\raggedleft
	\textbf{\@author}
	\end{minipage}
	\vspace*{0.5\fill}
	\begin{center}
		\linespread{3}
		\HUGE
		\centerline{\textbf{\@title}}
		\Large
		\centerline{\textbf{\@subtitle}}
		\normalsize
		\centerline{\@variant}
	\end{center}
	\begin{minipage}{\textwidth}
		\begin{center}
			\includesvg[height=6cm]{images/logo_minitel}
		\end{center}
	\end{minipage}
	\vspace*{\fill}

	\Large
	\begin{minipage}{0.3\textwidth}
	\linespread{1}
	\raggedright
	\includesvg[width=6cm]{images/logo_ecole}
	\end{minipage}
	\begin{minipage}{0.7\textwidth}
	\raggedleft
	\large
	\textbf{\@licence}
	\end{minipage}
	\newpage
	\normalsize
	\color{black}
	\pagenumbering{arabic}
}
\makeatother

%%%%%%%%%%%%%%%%%
% Miscellaneous %
%%%%%%%%%%%%%%%%%

% Pour sous-titrer les images et autres figures
\RequirePackage{caption}
	\captionsetup{hypcap=false}

% Liens hypertexte
\RequirePackage{bookmark} % Inclut hyperref par défaut
\hypersetup{
	colorlinks=true,
	urlcolor=blue!80!black,
	citecolor=PineGreen,
	linkcolor=minitelgreen2!70!black
}

\RequirePackage{makecell}