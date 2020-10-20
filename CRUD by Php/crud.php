<?php
/*******************************************************************************
    crud.php by Bill Weinman <http://bw.org/contact/>

    CRUD: Create, Read, Update, Delete --  Database example

    Copyright (c) 2009-2018 The BearHeart Group LLC

    1.1 bw - 2009-04-22 - Updated to work with PHP warnings turned on
    2.0.0 bw -- 2010-08-09 - Support for SQLite
    2.1.0 bw -- 2010-08-17 - Added UDFs for SQLite
    2.2.0 bw -- 2010-08-24 - Public release with support for both SQLite and MySQL
    2.3.0 bw -- 2010-09-04 - Added support for PostgreSQL
    2.2.8 bw -- 2012-01-27 - Public release
    3.6.4 bw -- 2018-04-08 - SQL EssT 2018 Update

*******************************************************************************/

define("VERSION", "3.6.4");

// ***** uncomment for PostgreSQL
// define("DBENGINE", "pgsql");
// define("PGSQLUSER", "sid");
// define("PGSQLPASS", "foo.bar");
// define("PGSQLDB", "album");
// *********************************

// ***** uncomment for SQLite 3
define("DBENGINE", "sqlite3");
define("DBFILE", "../db/album.db");
// *********************************

// ***** uncomment for MySQL
// define("DBENGINE", "mysql");
// define("MYSQLUSER", "web");
// define("MYSQLPASS", "");
// define("MYSQLDB", "album");
// *********************************

$album_fields = array (
    'title', 'artist', 'label', 'released'
);

$track_fields = array (
    'track_number', 'title', 'duration'
);

$months = array (
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
);

_init();
main();

function main()
{
    if(! isset($_REQUEST['a'])) $_REQUEST['a'] = '';
    jump($_REQUEST["a"]);
}

function _init( )
{
    global $CRUD;

    $CRUD['TITLE'] = "CRUD";
    $CRUD['SELF'] = $_SERVER["SCRIPT_NAME"];

    // loose "index.php" if nec (regexes are fugly in php. Feh.)
    $CRUD["SELF"] = preg_replace('/([\\/\\\])index\\.php$/i', '$1', $CRUD["SELF"]); 

    foreach ( array(
            'DBVERSION', 'BUTTONS', 'HIDDENS', 'MESSAGES', 'ERRORS', 'CONTENT', 'PRECONTENT', 'POSTCONTENT',
            'Atitle', 'Aartist', 'Alabel', 'Areleased_day', 'Areleased_month', 'Areleased_year',
            'Ttrack_number', 'Ttitle', 'Tduration'
            ) as $v )
        $CRUD[$v] = '';

    switch(DBENGINE) {
        case 'sqlite3':
            try {
                $dbh = new PDO('sqlite:' . DBFILE, 'unused', 'unused');
                $dbh->sqliteCreateFunction('SEC_TO_TIME', 'sec_to_time', 1);        // custom functions ...
                $dbh->sqliteCreateFunction('TIME_TO_SEC', 'time_to_sec', 1);
                $dbh->sqliteCreateAggregate('SUM_SEC_TO_TIME',
                    'sum_sec_to_time_step', 'sum_sec_to_time_finalize', 1);
                $sth = $dbh->query('SELECT SQLITE_VERSION()');
                $CRUD['DBVERSION'] = 'SQLite ' . $sth->fetchColumn(0);
            } catch (PDOException $e) {
                error($e->getMessage());
            }
            break;
        case 'mysql':
            // connect to the database (persistent)
            try {
                $dbh = new PDO('mysql:host=localhost;dbname=' . MYSQLDB, MYSQLUSER, MYSQLPASS,
                    array( PDO::ATTR_PERSISTENT => true ));
                $sth = $dbh->query("SHOW VARIABLES WHERE Variable_name = 'version'");
                $CRUD['DBVERSION'] = 'MySQL server version ' . $sth->fetchColumn(1);
            } catch (PDOException $e) {
                error($e->getMessage());
            }
            break;
        case 'pgsql':
            // connect to the database (persistent)
            try {
                $dbh = new PDO('pgsql:host=localhost;port=5432;dbname=' . PGSQLDB, PGSQLUSER, PGSQLPASS,
                    array( PDO::ATTR_PERSISTENT => true ));
                $dbh->exec("set client_encoding to 'latin1'");
                $sth = $dbh->query('SELECT VERSION()');
                $CRUD['DBVERSION'] = explode(' ', $sth->fetchColumn());
                $CRUD['DBVERSION'] = 'PostgreSQL server version ' . $CRUD['DBVERSION'][1];
            } catch (PDOException $e) {
                error($e->getMessage());
            }
            break;
        default:
            error('unsupported DBENGINE specified: ' . DBENGINE);
    }
    $CRUD['dbh'] = $dbh;
}

function page( $p )
{
    global $CRUD;   // used in the required files
    if( ! $p ) $p = "main";

    set_vars();

    require_once "assets/header.php";
    require_once "assets/$p.php";
    require_once "assets/footer.php";
    exit();
}

function jump( $action )
{
    switch($action) {
        case "add_album":
            do_add_album();
            break;
        case "album_action":
            do_album_action();
            break;
        case "album_update":
            do_album_update_action();
            break;
        case "track_add":
            do_track_add();
            break;
        case "track_update":
            do_track_update();
            break;
        case "album_delete_confirm":
            delete_album();
            break;
        case "track_delete_confirm":
            delete_track();
            break;
        default:    // default to show main page
            main_page();
    }
    return;
}

function main_page()
{
    list_albums();
    form_head('Add Album');
    javascript_focus( 'album', 'Atitle' );
    hidden('a', 'add_album');
    button('add_album', ' Add Album ');
    page('main');
}

// album functions

function list_albums()
{
    global $album_fields;

    $sth = get_albums_sql();

    // $a is an accumulator for the output string
    $a = subheading('Albums');
    $a .= "<table class=\"results\">\n";

    // get the first row
    $row = $sth->fetch(PDO::FETCH_ASSOC);

    if( ! $row ) {
        message("There are no albums in the database. Add some!");
        return;
    }

    $col_names = array_keys($row);

    // head of table
    $a .= "<tr>";   // table row for headings
    foreach( $album_fields as $name ) {
        $name = display_name($name);  // uppercase the first char
        $a .= "<td class=\"column_head\">$name</td>\n";
    }

    // space for the links at the right side of the results table
    $a .= "<td class=\"column_head\">Action</td>\n";

    $row_count = 0;
    do {
        $a .= album_result_row($row);
        $row_count++;
    } while ( $row = $sth->fetch(PDO::FETCH_ASSOC) );

    $a .= "</tr>\n"; 
    $a .= "</table>\n"; 

    message( "There are only " . number_format($row_count) . " albums in the database. Add some more!");
    content($a);
}

function display_tracks ( $album_id ) 
{
    global $track_fields;
    
    // $a is an accumulator for the output string
    $a = subheading('Tracks');
    $a .= "<table class=\"results\">\n";

    // head of table
    $a .= "<tr>";   // table row for headings
    foreach( $track_fields as $name ) {
        $name = display_name($name);  // uppercase the first char
        $a .= "<td class=\"column_head\">$name</td>\n";
    }

    // space for the links at the right side of the results table
    $a .= "<td class=\"column_head\">Action</td>\n";

    $a .= new_track($album_id);
    $sth = get_tracks_sql($album_id);

    $row_count = 0;
    while ( $row = $sth->fetch(PDO::FETCH_ASSOC) ) {
        $a .= track_result_row($row);
        $row_count++;
    }

    $a .= "</table>\n";

    content($a);
}

function album_result_row( $row )
{
    global $album_fields;
    $a = "<tr>\n";
    foreach( $album_fields as $v ) {
        if( $v == 'title' && ($len = get_album_length($row['id'])) ) {
            $row[$v] .= "<span class=\"small light\">&nbsp;&nbsp;$len</span>";
        }
        $a .= "<td class=\"cell_value\">" . $row[$v] . "</td>\n";
    }
    $a .= album_action_buttons( $row['id'] );   // the action links for this row
    $a .= "</tr>\n";
    return $a;
}

function album_action_buttons( $id )
{
    global $CRUD;
    $link_back = $CRUD['SELF'];

    $a = "<td class=\"cell_value\">";
    $a .= start_form() .
        action_button('edit', 'Edit') .
        action_button('delete', 'Delete') .
        hidden_element('a', 'album_action') .
        hidden_element('id', $id) .
        end_form();
    $a .= "</td>";
    return $a;
}

function album_edit( $id )
{
    global $CRUD, $album_fields;
    $album = fetch_album($id);  // get the album from the database
    if(! $album) {
        message("Album not found.");
        main_page();
    }

    foreach ( $album_fields as $f ) {
        if($f == 'released') {
            $CRUD[ 'A' . $f ] = fill_album_released_date($album[$f]);
        } else {
            $CRUD[ 'A' . $f ] = $album[$f];
        }
    }
    form_head('Edit Album');
    button('album_update', ' Update ');
    button('done', ' Done ');
    hidden('a', 'album_update');
    hidden('id', $id);

    display_tracks( $id );

    page('main');
}

function album_delete_confirm( $id )
{
    $album = fetch_album( $id );
    $a = start_form();
    $a .= heading('Confirm Delete');
    $a .= "<p> Are you sure you want to delete the album \"" .
        $album['title'] .
        "\" and all its tracks?" . 
        "</p>\n";
    $a .= "<p>\n";
    $a .= button_element('cancel', " Cancel ") . "&nbsp;";
    $a .= button_element('delete_confirm', " Confirm Delete ");
    $a .= "</p>\n";
    $a .= hidden_element('a', 'album_delete_confirm') . hidden_element('id', $album['id']);
    $a .= end_form();
    content($a);
    page('plain');
}

function track_delete_confirm( $track_id, $album_id )
{
    $album = fetch_album( $album_id );
    $track = fetch_track( $track_id );

    $a = start_form();
    $a .= heading('Confirm Delete');
    $a .= "<p> Are you sure you want to delete the track \"" .
        $track['title'] .
        "\" from the album \"" .
        $album['title'] .
        "\"?" . 
        "</p>\n";
    $a .= "<p>\n";
    $a .= button_element('cancel', " Cancel ") . "&nbsp;";
    $a .= button_element('delete_confirm', " Confirm Delete ");
    $a .= "</p>\n";
    $a .= hidden_element('a', 'track_delete_confirm') . hidden_element('id', $track['id']);
    $a .= end_form();
    content($a);
    page('plain');
}

function do_album_action()
{
    $id = $_REQUEST['id'];
    if(isset($_REQUEST['edit'])) album_edit($id);
    if(isset($_REQUEST['delete'])) album_delete_confirm($id);
}

function do_album_update_action()
{
    $id = $_REQUEST['id'];
    if(isset($_REQUEST['album_update'])) do_update_album();
    if(isset($_REQUEST['done'])) main_page();
    main_page();
}

function do_update_album()
{
    global $album_fields;

    foreach( $album_fields as $f ) {
        $fieldname = 'A' . $f;
        if ($f == "released") {
            $album[$f] = get_album_released_date();
        } elseif ($_REQUEST[$fieldname]) {
            $album[$f] = get_field($fieldname);
        }
    }
    $album['id'] = $_REQUEST['id'];

    update_album_sql( $album );

    $title = $album['title'];
    message("Album \"$title\" updated.");
    album_edit($album['id']);
}

function do_add_album()
{
    global $CRUD, $album_fields;

    foreach( $album_fields as $f ) {
        $fieldname = 'A' . $f;
        if ($f == "released") {
            $album[$f] = get_album_released_date();
        } elseif ($_REQUEST[$fieldname]) {
            $album[$f] = get_field($fieldname);
        }
    }

    if( ! isset( $album['title'] ) ) error_message( "Album must have a Title" );
    if( ! isset( $album['artist'] ) ) error_message( "Album must have an Artist" );
    if( error_message() ) {
        foreach ( $album_fields as $f ) {
            $CRUD[ 'A' . $f ] = isset($album[$f]) ? $album[$f] : '';
            if( $f == 'released' and isset($album[$f]) ) fill_album_released_date( $album[$f] );
        }
        main_page();
    }
    create_album( $album );
    main_page();
}

function create_album( $album )
{
    $id = insert_album_sql( $album );

    $title = $album['title'];
    message("Album \"$title\" added.");
    message("You may now add tracks below.");

    javascript_focus( 'add_track', 'Ttrack_number' );
    album_edit( $id );
}

function delete_album()
{
    $id = $_REQUEST['id'];
    $album = fetch_album( $id );
    $title = $album['title'];

    if(isset($_REQUEST['cancel'])) {
        message("Cancelled delete of album \"$title\"");
        main_page();
    }

    delete_album_sql($id);

    message("Album \"$title\" deleted.");
    main_page();
}

function album_month_select( )
{
    global $CRUD, $months;
    $a = "<select name=\"Areleased_month\">";
    $a .= "<option value=\"0\">-- Select a Month --</option>\n";
    for ( $i = 1; $i <= 12; $i++ ) {
        $m = $months[$i - 1];
        $selected = ( sprintf("%02d", $i) == $CRUD['Areleased_month'] ) ? " selected" : "";
        $a .= "<option value=\"$i\"$selected>$m</option>\n";
        }
    $a .= "</select>\n";
    echo($a);
}

function fill_album_released_date( $f )
{
    global $CRUD;
    if (!isset($f)) $f = '--';  // update for PHP 7
    list( $year, $month, $day ) = explode('-', $f, 3);

    $CRUD['Areleased_year'] = $year;
    $CRUD['Areleased_day'] = $day;
    $CRUD['Areleased_month'] = $month;
}

function get_album_released_date()
{
    $year = get_field('Areleased_year');
    $month = get_field('Areleased_month');
    $day = get_field('Areleased_day');

    // make sure they're numeric
    if( ! is_numeric($year) ) $year = 0;
    if( ! is_numeric($month) ) $month = 0;
    if( ! is_numeric($day) ) $day = 0;

    if( $year < 1 ) return NULL;
    if( $month < 1 ) $month = 1;
    if( $day < 1 ) $day = 1;

    // an SQL date looks like: "2009-01-24"
    return sprintf("%04d-%02d-%02d", $year, $month, $day);
}

// track functions

function do_track_update()
{
    global $CRUD, $track_fields;
    $album_id = $_REQUEST['album_id'];
    $track_id = $_REQUEST['id'];

    if(isset($_REQUEST['track_delete'])) track_delete_confirm( $track_id, $album_id );

    $track = validate_track_input();
    $track['id'] = $track_id;

    update_track_sql($track);

    $track_number = $track['track_number'];
    $title = $track['title'];
    message("Track $track_number ($title) updated.");

    // reset the display variables
    $CRUD['Ttrack_number'] = "";
    $CRUD['Ttitle'] = "";
    $CRUD['Tduration'] = "";
    album_edit( $album_id );
}

function do_track_add ()
{
    global $CRUD;
    $album_id = $_REQUEST['album_id'];

    $track = validate_track_input();
    $track['album_id'] = $album_id;
    $id = insert_track_sql($track);

    $track_number = $track['track_number'];
    $title = $track['title'];
    message("Track $track_number ($title) added.");

    $CRUD['Ttrack_number'] = "";
    $CRUD['Ttitle'] = "";
    $CRUD['Tduration'] = "";

    javascript_focus( 'add_track', 'Ttrack_number' );
    album_edit( $album_id );
}

function validate_track_input ()
{
    global $CRUD;
    $album_id = $_REQUEST['album_id'];

    $track_number = get_field('Ttrack_number');
    $title = get_field('Ttitle');
    $duration = get_field('Tduration');

    $CRUD['Ttrack_number'] = $track_number;
    $CRUD['Ttitle'] = $title;
    $CRUD['Tduration'] = $duration;

    // check for errors
    if( ! strlen($track_number) ) error_message("A track must have a track number");
    if( ! $title ) error_message("A track must have a title");
    if( ! $duration ) error_message("A track must have a duration");
    if( preg_match( '/[^0-9:]/', $duration ) )
        error_message("Duration must be in seconds, or minutes and seconds, e.g., \"7:32\"");

    // a little extra checking for duration
    $duration_array = explode(':', $duration );
    $duration_count = count($duration_array);
    if( $duration_count == 1 )
        $db_duration = $duration_array[0];
    elseif( $duration_count == 2)
        $db_duration = ( $duration_array[0] * 60 ) + $duration_array[1];
    else error_message("Duration must be in seconds, or minutes and seconds, e.g., \"7:32\"");

    // report any errors
    if( error_message() ) {
        album_edit($album_id);
    }

    $track['album_id'] = $album_id;
    $track['track_number'] = $track_number;
    $track['title'] = $title;
    $track['duration'] = $db_duration;

    return $track;
}

function new_track ( $album_id )
{
    global $CRUD;
    $link_back = $CRUD['SELF'];
    $a = start_form( 'add_track' );
    $a .= "<tr>\n";
    $a .= "<td class=\"cell_value\">" . track_input_text( 'Ttrack_number', 'Ttrack_number', $CRUD['Ttrack_number'] ) . "</td>\n";
    $a .= "<td class=\"cell_value\">" . track_input_text( 'Ttitle', 'Ttitle', $CRUD['Ttitle'] ) . "</td>\n";
    $a .= "<td class=\"cell_value\">" . track_input_text( 'Tduration', 'Tduration', $CRUD['Tduration'] ) . "</td>\n";
    $a .= "<td class=\"cell_value\">" . action_button( 'track_add', ' Add ' ) . "</td>\n";
    $a .= hidden_element( 'a', 'track_add' ) . hidden_element( 'album_id', $album_id ) . "\n";
    $a .= "</tr>\n";
    $a .= end_form();
    return $a;
}

function track_result_row( $row )
{
    $a = start_form();
    $a .= "<tr>\n";
    $a .= "<td class=\"cell_value\">" . track_input_text( 'Ttrack_number', 'Ttrack_number', $row['track_number'] ) . "</td>\n";
    $a .= "<td class=\"cell_value\">" . track_input_text( 'Ttitle', 'Ttitle', $row['title'] ) . "</td>\n";
    $a .= "<td class=\"cell_value\">" . track_input_text( 'Tduration', 'Tduration', $row['disp_duration'] ) . "</td>\n";
    $a .= "<td class=\"cell_value\">" . action_button( 'track_update', ' Update ' ) .
        action_button( 'track_delete', ' Delete ' ) . "</td>\n";
    $a .= hidden_element( 'a', 'track_update' ) . hidden_element( 'album_id', $row['album_id'] ) . hidden_element( 'id', $row['id'] ) . "\n";
    $a .= "</tr>\n";
    $a .= end_form();
    return $a;
}

function delete_track()
{
    global $CRUD;

    $id = $_REQUEST['id'];
    $track = fetch_track( $id );
    $title = $track['title'];

    if(isset($_REQUEST['cancel'])) {
        message("Cancelled delete of track \"$title\"");
        album_edit($track['album_id']);
    }

    delete_track_sql($id);

    message("Track \"$title\" deleted.");
    album_edit($track['album_id']);
}

//
// database interface functions and SQL
//

// perform the query and return sth (statement handle)
function get_albums_sql ( )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    $query = ' SELECT * FROM album ORDER BY title ';
    $sth = $dbh->prepare($query);
    if($sth) $sth->execute();
    else error('get_albums_sql: select prepare returned no statement handle');

    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );

    return($sth);
}

// perform the query and return sth (statement handle)
function get_tracks_sql ( $album_id )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    switch(DBENGINE) {
        case 'mysql':
            $query = '
                SELECT 
                    id, album_id, title, track_number,
                    CONCAT_WS(
                        ":",
                        duration DIV 60,
                        LPAD( duration MOD 60, 2, "0" )
                    ) AS disp_duration
                    FROM track
                    WHERE album_id = ?
                    ORDER BY track_number, id
            ';
            break;
        case 'sqlite3':
            $query = "
                SELECT 
                    id, album_id, title, track_number, SEC_TO_TIME(duration) AS disp_duration
                    FROM track
                    WHERE album_id = ?
                    ORDER BY track_number, id
            ";
            break;
        case 'pgsql':
            $query = "
                SELECT 
                    id, album_id, title, track_number,
                    duration / 60 || ':' || TO_CHAR(duration % 60, 'FM09') AS disp_duration
                    FROM track
                    WHERE album_id = ?
                    ORDER BY track_number, id
            ";
            break;
        default:
            error("get_tracks_sql: no SQL for engine " . DBENGINE);
            return NULL;
    }

    $sth = $dbh->prepare($query);
    if($sth) $sth->execute( array( $album_id ) );
    else error("get_tracks_sql: select prepare returned no statement handle (" . db_message($dbh) . ")");
    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );

    return($sth);
}

function insert_album_sql( $album )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    $query = '
        INSERT INTO album
            ( title, artist, label, released )
            VALUES ( ?, ?, ?, ? )
    ';

    $sth = $dbh->prepare($query);
    if($sth) $sth->execute(
        array( @$album['title'], @$album['artist'], @$album['label'], @$album['released'] )
    );
    else error("insert_album_sql: insert prepare returned no statement handle");

    // check for errors
    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );

    // make pgsql work like the others
    if(DBENGINE == 'pgsql') {
        $id = $dbh->lastInsertId('album_id_seq');
    } else {
        $id = $dbh->lastInsertId();
    }

    return($id);
}

function insert_track_sql ( $track )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    // database insert
    $query = '
        INSERT INTO track
            ( album_id, track_number, title, duration )
            VALUES ( ?, ?, ?, ? )
    ';

    $sth = $dbh->prepare($query);
    if($sth) $sth->execute( array( @$track['album_id'], @$track['track_number'], @$track['title'], @$track['duration']) );
    else error("insert_track_sql: insert prepare returned no statement handle");

    // check for errors from the database ops
    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );

    // make pgsql work like the others
    if(DBENGINE == 'pgsql') {
        $id = $dbh->lastInsertId('track_id_seq');
    } else {
        $id = $dbh->lastInsertId();
    }

    return($id);
}

function update_album_sql( $album )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    $query =  '
        UPDATE album 
            SET title = ?, artist = ?, label = ?, released = ?
            WHERE id = ?
    ';

    $sth = $dbh->prepare($query);
    if($sth) $sth->execute( array( @$album['title'], @$album['artist'], @$album['label'], @$album['released'], @$album['id'] ) );
    else error("update_album_sql: update prepare returned no statement handle");

    // check for errors
    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );
}

function update_track_sql ( $track )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    $query = '
        UPDATE track
            SET track_number = ?, title = ?, duration = ?
            WHERE id = ?
    ';
    $sth = $dbh->prepare($query);
    if($sth) $sth->execute( array( @$track['track_number'], @$track['title'], @$track['duration'], @$track['id'] ) );
    else error("update_track_sql: update prepare returned no statement handle");

    // check for errors from the database ops
    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );
}

function delete_album_sql( $id )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    $query1 =  "DELETE FROM track  WHERE album_id = ?";
    $query2 =  "DELETE FROM album  WHERE id = ?";

    // delete tracks
    $sth = $dbh->prepare($query1);
    if($sth) $sth->execute( array( $id ) );
    else error("delete_album_sql: delete prepare returned no statement handle");

    // check for errors
    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );

    // delete album
    $sth = $dbh->prepare($query2);
    if($sth) $sth->execute( array( $id ) );
    else error("delete_album_sql: delete prepare returned no statement handle");

    // check for errors
    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );
}

function delete_track_sql ( $id )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    $query =  "DELETE FROM track WHERE id = ?";

    // delete track
    $sth = $dbh->prepare($query);
    if($sth) $sth->execute( array( $id ) );
    else error("delete_track: delete prepare returned no statement handle");

    // check for errors
    $err = $sth->errorInfo();
    if($err[0] != 0) error( $err[2] );
}

// "fetch_" functions are for getting one row
function fetch_album( $id )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];
    $query = 'SELECT * FROM album WHERE id = ?';
    $sth = $dbh->prepare($query);
    if($sth) $sth->execute( array( $id ) );
    else error("fetch_album: select prepare returned no statement handle");
    return $sth->fetch(PDO::FETCH_ASSOC);
}

function fetch_track( $id )
{
    global $CRUD;
    $dbh = $CRUD['dbh'];

    switch(DBENGINE) {
        case 'mysql':
            $query = '
                SELECT 
                    id, album_id, title, track_number,
                    CONCAT_WS(
                        ":",
                        duration DIV 60,
                        LPAD( duration MOD 60, 2, "0" )
                    ) AS disp_duration
                    FROM track
                    WHERE id = ?
            ';
            break;
        case 'sqlite3':
            $query = "
                SELECT 
                    id, album_id, title, track_number, SEC_TO_TIME(duration) AS disp_duration
                    FROM track
                    WHERE id = ?
            ";
            break;
        case 'pgsql':
            $query = "
                SELECT 
                    id, album_id, title, track_number,
                    duration / 60 || ':' || TO_CHAR(duration % 60, 'FM09') AS disp_duration
                    FROM track
                    WHERE id = ?
            ";
            break;
        default:
            $query = '';
            break;
    }

    $sth = $dbh->prepare($query);
    if($sth) $sth->execute( array( $id ) );
    else error("fetch_track: select prepare returned no statement handle");
    return $sth->fetch(PDO::FETCH_ASSOC);
}

// custom functions for SQLite 3

// SEC_TO_TIME( seconds INTEGER )
function sec_to_time( $sec )
{
    if(is_null($sec)) return NULL;
    $sec = intval($sec);    // make sure it's an integer
    $s = $sec % 60;
    $m = $sec / 60;
    return sprintf('%d:%02d', $m, $s);
}

// TIME_TO_SEC( time TEXT )  -- 'mm:ss'
function time_to_sec( $time )
{
    if(is_null($time)) return NULL;
    $t = explode(':', $time, 2);
    $m = intval($t[0]);
    $s = intval($t[1]);
    return ( $m * 60 ) + $s;
}

// SUM_SEC_TO_TIME
function sum_sec_to_time_step ($context, $rownumber, $value)
{
    if(is_null($value)) return $context;
    if(is_null($context)) $context = 0;
    $context += intval($value);     // accumulate the sum of the values
    return $context;
}

function sum_sec_to_time_finalize ( $context, $rownumber )
{
    $sec = $context;
    $s = $sec % 60;
    $m = $sec / 60;
    $h = 0;
    if($m > 60) {
        $h = $m / 60;
        $m = $m % 60;
    }
    if($h) return sprintf('%d:%02d:%02d', $h, $m, $s);
    else return sprintf('%02d:%02d', $m, $s);
}

// get_album_length
function get_album_length($id)
{
    global $CRUD;
    if(! in_array(DBENGINE, array('sqlite3', 'pgsql'))) return NULL;
    $dbh = $CRUD['dbh'];
    $query = '';
    switch(DBENGINE) {
        case 'sqlite3':
            $query = "SELECT SUM_SEC_TO_TIME(duration) FROM track WHERE album_id = ?";
            break;
        case 'pgsql':
            $query = "
                SELECT sd.dur / 60 || ':' || TO_CHAR(sd.dur % 60, 'FM09')
                    FROM (
                        SELECT SUM(duration) AS dur FROM track WHERE album_id = ?
                    ) AS sd
            ";
            break;
    }
    if($query == '') return NULL;
    $sth = $dbh->prepare($query);
    $sth->execute(array($id));
    return $sth->fetchColumn();
}

// utility functions

function set_vars( )
{
    global $CRUD;
    if(isset($CRUD["_BTN_ARRAY"])) foreach ( $CRUD["_BTN_ARRAY"] as $m ) $CRUD["BUTTONS"] .= $m;
    if(isset($CRUD["_HID_ARRAY"])) foreach ( $CRUD["_HID_ARRAY"] as $m ) $CRUD["HIDDENS"] .= $m;
    if(isset($CRUD["_MSG_ARRAY"])) foreach ( $CRUD["_MSG_ARRAY"] as $m ) $CRUD["MESSAGES"] .= $m;
    if(isset($CRUD["_ERR_ARRAY"])) foreach ( $CRUD["_ERR_ARRAY"] as $m ) $CRUD["ERRORS"] .= $m;
    if(isset($CRUD["_CON_ARRAY"])) foreach ( $CRUD["_CON_ARRAY"] as $m ) $CRUD["CONTENT"] .= $m;
    if(isset($CRUD["_PRE_ARRAY"])) foreach ( $CRUD["_PRE_ARRAY"] as $m ) $CRUD["PRECONTENT"] .= $m;
    if(isset($CRUD["_POST_ARRAY"])) foreach ( $CRUD["_POST_ARRAY"] as $m ) $CRUD["POSTCONTENT"] .= $m;
}

// make a field name display-friendly
function display_name ($n)
{
    // start with the exceptions
    if ($n == 'track_number') return 'Track';

    $n = strtr( $n, '_', ' ' );     // make _'s into spaces. 
    $n = ucwords( $n );
    return $n;
}

//
// shortcuts and setter-getters
//


// shortcut for reading field data from _REQUEST
function get_field ( $f )
{
    return stripslashes($_REQUEST[$f]);
}

// shortcuts for html elements

function heading ( $s )
{
    return "<p class=\"heading\">$s</p>\n";
}

function subheading ( $s )
{
    return "<p class=\"subheading\">$s</p>\n";
}

function start_form ( $name = "" )
{
    global $CRUD;
    $self = $CRUD['SELF'];

    if($name) $name = " name=\"$name\"";
    return "<form action=\"$self\" method=\"POST\"$name>\n";
}

function end_form ()
{
    return "</form>\n";
}

function track_input_text( $c, $n, $v )
{
    return "<input class=\"$c\" type=\"text\" name=\"$n\" value=\"$v\">";
}

function hidden_element( $n, $v )
{
    return "<input type=\"hidden\" name=\"$n\" value=\"$v\">";
}

function button_element( $n, $v )
{
    return "<input type=\"submit\" name=\"$n\" value=\"$v\">";
}

function action_button( $n, $v )
{
    return "<input class=\"action_button\" type=\"submit\" name=\"$n\" value=\"$v\">";
}

function javascript_focus( $form, $field )
{
    $a = "<script language=\"javascript\"> <!--\n";
    $a .= "  document.$form.$field.focus();\n";
    $a .= "// --> </script>\n";
    postcontent( $a );
}

// setter/getters

function form_head( $s )
{
    global $CRUD;
    if($s) $CRUD["FORM_HEAD"] = $s;
    return $CRUD["FORM_HEAD"];
}

// setters for display arrays

function button( $n, $v )
{
    global $CRUD;
    $CRUD["_BTN_ARRAY"][] = "<input class=\"submit_button\" type=\"submit\" name=\"$n\" value=\"$v\">\n";
}

function hidden( $n, $v )
{
    global $CRUD;
    $CRUD["_HID_ARRAY"][] = "<input type=\"hidden\" name=\"$n\" value=\"$v\">\n";
}

function content( $s )
{
    global $CRUD;
    $CRUD["_CON_ARRAY"][] = "\n<div class=\"content\">$s</div>\n";
}

function precontent( $s )
{
    global $CRUD;
    $CRUD["_PRE_ARRAY"][] = $s;
}

function postcontent( $s )
{
    global $CRUD;
    $CRUD["_POST_ARRAY"][] = $s;
}

// db_message( $dbh )
// get the error message element from the array
// (PHP functions aren't first-class, so foo()[n] doesn't work.)
function db_message($dbh)
{
    $e = $dbh->errorInfo();
    return $e[2];
    
}

function message()
{
    global $CRUD;
    $args = func_get_args();
    if(count($args) < 1) return;
    $s = vsprintf(array_shift($args), $args);
    $CRUD["_MSG_ARRAY"][] = "<p class=\"message\">$s</p>\n";
}

function error_message()
{
    global $CRUD;
    $args = func_get_args();
    if(count($args) > 0) {
        $s = vsprintf(array_shift($args), $args);
        $CRUD["_ERR_ARRAY"][] = "<p class=\"error_message\">$s</p>\n";
    }
    return isset($CRUD["_ERR_ARRAY"]) ? $CRUD["_ERR_ARRAY"] : array();
}

function error( $s )
{
    error_message($s);
    page('plain');
}

?>
