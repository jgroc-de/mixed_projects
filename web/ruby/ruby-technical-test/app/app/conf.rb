configure do
	db = DB.reverse
	i = 0
	db.each do |value|
		value[:id] = i
		i += 1
	end
	set :database, db
	set :comments, COMMENTS.reverse
	set :name, "<script>alert('lol')</script>"
	set :intro, "Galaxy traveller looking for an internship paid 42 BTC/month"
	set :photo, "http://images.amcnetworks.com/ifc.com/wp-content/uploads/2015/12/HitchhikersGuidetoTheGalaxy.jpg"
	set :link, "https://jgroc-de.github.io/"
	set :pseudo, "jgroc-de"
end
