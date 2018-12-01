var moment = Moment.moment

//GLOBALS
var name;
var startDate;
var endDate;
var speciality;
var numFamPrac = 0;
var numIntMed = 0;
var numPediatrics = 0;
var numAdult = 0;
var numGeri = 0;
var numOB = 0;


function onFormSubmit() {
  main();
}

/*
* Main:
* Run this function. It opens the form, saves the responses, and then parses the form and schedules the time off.
*/
function main() {
  
  var form = FormApp.openByUrl('https://docs.google.com/forms/d/19iKjKvxzxEcOOAigZGJqKfhFLndm0zSYHu0nZKvaXXw/edit?ts=5acbfea7');
  var responses = form.getResponses();

  /*for (var i = 0; i < responses.length; i++) {
    var formResponse = responses[i];
    parseForm(i, formResponse);
    schedule();
  }*/
  var formResponse = responses[responses.length - 1]
  parseForm(responses.length - 1, formResponse);
  schedule();
}

/*
* parseForm(i: the number assigned to the response, formResponse: The array of responses)
* This function saves the responses to the proper variables
*/
function parseForm(i, formResponse) {
  var itemResponses = formResponse.getItemResponses();
  
  for (var j = 0; j < itemResponses.length; j++) {
    var itemResponse = itemResponses[j];
    Logger.log('Response #%s to the question "%s" was "%s"',
      (i + 1).toString(),
      itemResponse.getItem().getTitle(),
      itemResponse.getResponse());
    if (j == 0) {
      name = itemResponse.getResponse();
    }
    else if (j == 1) {
      startDate = itemResponse.getResponse();
    }
    else if (j == 2) {
      endDate = itemResponse.getResponse();
    }
    else if (j == 6) {
      speciality = itemResponse.getResponse();
    }
  }
  tallySpecialities(speciality);
  
}

/*
 * schedule() 
 * This function schedules each responder on a Google Calendar.
 */
function schedule() {
  //var calendar = CalendarApp.getDefaultCalendar();
  var calendar = CalendarApp.getCalendarById('evv3pj3okpp2u82li229q19hks@group.calendar.google.com');
  var giveTimeOff = true;

  //Check to see if people have already taken those days off.
  var events = calendar.getEvents(moment(startDate).toDate(), moment(endDate).toDate())
  for (var i = 0; i < events.length; i++) {
    if (events.length > 3) {
      Logger.log('TOO MANY COOKS!!! @%s', events[i].getTitle());
      giveTimeOff = false;
    } else if (numFamPrac > 2 || numIntMed > 2 || numPediatrics > 2 ||
               numAdult > 2 || numGeri > 2 || numOB > 2) {
      Logger.log('TOO MANY COOKS!!!');
      giveTimeOff = false;
    }
      
  }
  
  if (giveTimeOff) {
    name = name + "\'s Time Off";
  
    var event = calendar.createEvent(name, moment(startDate).toDate() , moment(endDate).toDate());
    Logger.log('%s - %s', startDate, endDate);
  }
}

/*
 * tallySpecialities(spec: the speciality of the person who filled out the form)
 * This function keeps track of how many people are in each speciality. 
 */ 
function tallySpecialities(spec) {
  if (spec == 'Family Practice') {
    numFamPrac++;
  } else if (spec == 'Internal Medicine') {
    numIntMed++;
  } else if (spec == 'Pediatrics') {
    numPediatrics++;
  } else if (spec == 'Adult (18+)') {
    numAdult++;
  } else if (spec == 'Geriatric (55+)') {
    numGeri++;
  } else if (spec == 'OB') {
    numOB++;
  }
}