package main

import (
	"encoding/json"
	"errors"
	"io"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"path"
	"regexp"
	"strings"
)

// A Rating object mapping.
type Rating struct {
	Source string `json:"Source"`
	Value string `json:"Value"`
}

// An Movie object mapping.
type Movie struct {
	Title string `json:"Title"`
	Year int `json:"Year"`
	Rated string `json:"Rated"`
	Released string `json:"Released"`
	Runtime string `json:"Runtime"`
	Genre string `json:"Genre"`
	Director string `json:"Director"`
	Writer string `json:"Writer"`
	Actors string `json:"Actors"`
	Plot string `json:"Plot"`
	Language string `json:"Language"`
	Country string `json:"Country"`
	Awards string `json:"Awards"`
	Poster string `json:"Poster"`
	Ratings []Rating `json:"Ratings"`
	Metascore string `json:"Metascore"`
	ImdbRating string `json:"imdbRating"`
	ImdbVotes string `json:"imdbVotes"`
	ImdbID string `json:"imdbID"`
	Type string `json:"Type"`
	DVD string `json:"DVD"`
	BoxOffice string `json:"BoxOffice"`
	Production string `json:"Production"`
	Website string `json:"Website"`
	Response string `json:"Response"`
}

const API_KEY string = ""
const API_ENDPOINT string = "http://www.omdbapi.com/?"

func main()  {
	if len(os.Args) < 2 {
		log.Fatal("USAGE: MovieRenamer <file/directory name>")
		os.Exit(1)
	}
	fi, err := os.Stat(os.Args[1])
	if err != nil{
		log.Fatal("Failed to open file or directory.")
		os.Exit(1)
	}
	if fi.IsDir(){
		// TODO: Create a for loop for every file in the path.
	} else {
		err = parseFile(os.Args[1])
		if err != nil {
			log.Fatal("Failed to parse current file.")
			os.Exit(1)
		}
	}
}

func parseFile(filePath string) error {
	var re = regexp.MustCompile(` (\d{4}) `)
	// Split path and filename
	origPath, fileName := path.Split(filePath)

	// Get file extension
	ext := path.Ext(fileName)

	// Replace '.' in the filename
	fileName = strings.Replace(fileName, ".", " ", len(fileName))

	// Extract movie release year
	yearIndex := re.FindStringIndex(fileName)
	year := fileName[yearIndex[0]+1:yearIndex[1]-1]

	// Extract movie title
	name := fileName[:yearIndex[0]]

	// Get metadata from ODMBApi
	title, err := getMovieByTitle(name, year)
	if err != nil {
		log.Fatalf("Failed to get metdata for %s", name)
		os.Exit(1)
	}

	// Rename original file into the movie title and get folder.jpg poster
	os.Rename(filePath, origPath + title.Title + ext)
	return getPoster(title.Poster, origPath)
}

// Gets a movie metadata by movie title
func getMovieByTitle(title, year string) (Movie, error) {
	url := buildBaseUrL() + "t=" + strings.Replace(title, " ", "+", len(title)) + "&y=" + year
	res, err := http.Get(url)

	if err != nil {
		return Movie{}, err
	}

	resData, err := ioutil.ReadAll(res.Body)
	if err != nil {
		return Movie{}, err
	}

	var movie Movie
	json.Unmarshal(resData, &movie)

	return movie, nil
}

func getPoster(url, path string) error {
	res, err := http.Get(url)
	if err != nil {
		return err
	}
	defer res.Body.Close()

	if res.StatusCode != 200 {
		return errors.New("Received error status code")
	}
	
	file, err := os.Create(path + "folder.jpg")
	if err != nil {
		return err
	}

	defer file.Close()

	_, err = io.Copy(file, res.Body)
	if err != nil {
		return err
	}

	return nil
}

// Creates a base url for OMDBAPI requests.
func buildBaseUrL() string {
	return API_ENDPOINT + "apikey=" + API_KEY + "&"
}