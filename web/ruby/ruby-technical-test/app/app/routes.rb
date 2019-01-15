get "/" do
	erb :index
end

get "/article/:id" do |id|
	i = id.to_i
	if i < 0 || i >= settings.database.size
		redirect "/", 301
	else
		@script = true
		@post = settings.database[i]
		@comment = settings.comments[i]
		if i != 0
			@prev = "/article/#{i - 1}"
		end
		if i != settings.database.size - 1
			@next = "/article/#{i + 1}"
		end
			erb :article
	end
end

#oui ca se repete, c'est mal
post "/article/:id" do |id|
	i = id.to_i
	if i < 0 || i >= settings.database.size
		redirect "/", 301
	else
		if params['msg'] != ""
			settings.comments[i] << params['msg']
		end
		@script = true
		@post = settings.database[i]
		@comment = settings.comments[i]
		if i != 0
			@prev = "/article/#{i - 1}"
		end
		if i != settings.database.size - 1
			@next = "/article/#{i + 1}"
		end
			erb :article
	end
end

get "/star/:id" do |id|
	i = id.to_i
	if !session.has_key?("rating")
		session["rating"] = Array.new(0)
	end
	if i < 0 || i >= settings.database.size || session["rating"][i]
		status 404
	else
		session["rating"][i] = 1
		settings.database[i][:rating] = "#{settings.database[i][:rating].to_i + 1}"
	end
end
